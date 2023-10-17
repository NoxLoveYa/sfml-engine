#pragma once
#include "../headers/game.hpp"

namespace engine
{
    namespace main_scene
    {
        //variables
        inline std::string name = "Main";
        inline rigid_body_e *local_player;

        void render(scene_e &scene, sf::RenderWindow &render_window)
        {
            for (auto &rigid_body : scene.rigid_bodies)
            {
                rigid_body.render(render_window);
            }
            render_window.display();
        }

        void update(scene_e &scene, window_e &window)
        {
            sf::Event event;
            while (window.render_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.opened = false;
                }

                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.opened = false;
                            break;
                        default:
                            break;
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                local_player->apply_force(sf::Vector2f(0.f, -100.f));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                local_player->apply_force(sf::Vector2f(0.f, 100.f));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                local_player->apply_force(sf::Vector2f(-100.f, 0.f));
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                local_player->apply_force(sf::Vector2f(100.f, 0.f));

            for (auto &rigid_body : scene.rigid_bodies)
            {
                rigid_body.update(window.delta_time, &scene);
            }


            //rotate the player towards the mouse
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window.render_window);
            sf::Vector2f player_pos = local_player->get_position();
            float dx = mouse_pos.x - player_pos.x;
            float dy = mouse_pos.y - player_pos.y;
            float rotation = (std::atan2(dy, dx) * (180 / M_PI)) - 280.f;

            sf::Shape *lp_shape =  local_player->get_draw_shape();
            lp_shape->setRotation(rotation);
        }

        void load(scene_e &scene)
        {
            sf::Shape *shape_test = new sf::CircleShape (50, 3);
            shape_test->setFillColor(sf::Color::White);
            sf::Shape *shape_test2 = new sf::RectangleShape(sf::Vector2f(100.f, 100.f));
            shape_test->setFillColor(sf::Color::White);
            sf::FloatRect bounds = shape_test->getLocalBounds();
            shape_test->setOrigin(bounds.width / 2.f, bounds.height / 2.f);

            scene.add_rigid_body(rigid_body_e(sf::Vector2f(100.f, 100.f), sf::Vector2f(0, 0), 9.8f, 1.1f, shape_test2, true));
            local_player = scene.add_rigid_body(rigid_body_e(sf::Vector2f(300.f, 200.f), sf::Vector2f(0, 0), 9.8f, 1.1f, shape_test, true));
            
            printf("scene.rigid_bodies.size() = %lu\n", scene.rigid_bodies.size());
        }
    }
}
