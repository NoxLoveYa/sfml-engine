//main to test the p100 code

#include "../headers/engine.hpp"

void render(engine::scene_e &scene, sf::RenderWindow &render_window)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    render_window.draw(shape);
    render_window.display();
}
static void render2(engine::scene_e &scene, sf::RenderWindow &render_window)
{
    for (auto rigid_body : scene.rigid_bodies) {
        rigid_body.render(render_window);
    }
    render_window.display();
}

void update(engine::scene_e &scene, engine::window_e &window)
{
    sf::Event event;
    while (window.render_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.opened = false;
            return;
        }
    }
}

int main(void)
{
    using namespace engine;

    window_e window(800, 600, "My SFML engine !!!");
    
    scene_manager_e *scene_manager = window.get_scene_manager();
    scene_manager->add_scene(scene_e("Main menu", render, update));
    scene_manager->add_scene(scene_e("Second menu", render2, update));
    scene_manager->set_current_scene("Second menu");

    sf::Shape *shape_test = new sf::CircleShape(10.f);
    shape_test->setFillColor(sf::Color::White);
    rigid_body_e test(sf::Vector2f(100.f, 100.f), sf::Vector2f(0, 0), 0.0f, shape_test);

    scene_manager->add_rigid_body(test);

    while (window.opened) {
        window.clear();
        window.render();
    }
    return 0;
}