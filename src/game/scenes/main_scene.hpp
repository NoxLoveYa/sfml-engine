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
        }

        void load(scene_e &scene)
        {
            sf::Shape *shape_test = new sf::CircleShape (50, 3);
            shape_test->setFillColor(sf::Color::White);
            sf::Shape *shape_test2 = new sf::RectangleShape(sf::Vector2f(100.f, 100.f));
            shape_test->setFillColor(sf::Color::White);

            scene.add_rigid_body(rigid_body_e(sf::Vector2f(100.f, 100.f), sf::Vector2f(0, 0), 9.8f, 1.1f, shape_test2, true));
            local_player = scene.add_rigid_body(rigid_body_e(sf::Vector2f(200.f, 200.f), sf::Vector2f(0, 0), 9.8f, 1.1f, shape_test, true));
            
            printf("scene.rigid_bodies.size() = %lu\n", scene.rigid_bodies.size());
        }
    }
}
