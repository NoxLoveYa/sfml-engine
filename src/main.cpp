//main to test the p100 code

#include "headers/engine.hpp"

void render(sf::RenderWindow &render_window)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    render_window.draw(shape);
    render_window.display();
}
void render2(sf::RenderWindow &render_window)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);
    render_window.draw(shape);
    render_window.display();
}

void update(engine::window_e &window)
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

    while (window.opened) {
        window.clear();
        window.render();
    }
    return 0;
}