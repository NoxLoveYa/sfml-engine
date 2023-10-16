#include "../headers/engine.hpp"

namespace engine
{
    //scene_manager_e
    void scene_manager_e::render(sf::RenderWindow &render_window)
    {
        this->current_scene.render(render_window);
    }

    void scene_manager_e::add_scene(scene_e scene)
    {
        scenes.push_back(scene);
    }

    void scene_manager_e::remove_scene(scene_e scene)
    {
        scenes.erase(std::remove(scenes.begin(), scenes.end(), scene), scenes.end());
    }

    void scene_manager_e::set_current_scene(scene_e scene)
    {
        this->current_scene.clear();
        this->current_scene = scene;
    }

    scene_e scene_manager_e::get_current_scene()
    {
        return this->current_scene;
    }

    std::string scene_e::get_name()
    {
        return this->name;
    }
}