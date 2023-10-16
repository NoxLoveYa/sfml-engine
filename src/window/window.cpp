#include "../headers/engine.hpp"

namespace engine
{
    void window_e::set_framerate(int framerate)
    {
        this->framerate = framerate;
        this->render_window.setFramerateLimit(this->framerate);
    }

    void window_e::clear()
    {
        this->render_window.clear(sf::Color::Black);
    }

    void window_e::render()
    {
        if (this->scene_manager.get_current_scene().get_name() == "null")
            return;
        this->scene_manager.render(this->render_window);
        this->delta_time = this->delta_timer.restart().asSeconds();
    }
}