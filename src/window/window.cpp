#include "../headers/engine.hpp"

namespace engine
{
    void window::set_framerate(int framerate)
    {
        this->framerate = framerate;
        this->render_window.setFramerateLimit(this->framerate);
    }

    void window::clear()
    {
        this->render_window.clear(sf::Color::Black);
    }

    void window::render()
    {
        this->scene_manager.render(this->render_window);
        this->delta_time = this->delta_timer.restart().asSeconds();
    }
}