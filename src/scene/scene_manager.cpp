#include "../headers/engine.hpp"

namespace engine
{
    //scene_manager_e
    void scene_manager_e::render(window_e &window)
    {
        this->current_scene.update(window);
        this->current_scene.render(window.render_window);
    }

    scene_e scene_manager_e::get_current_scene()
    {
        return this->current_scene;
    }

    scene_e scene_manager_e::get_scene(std::string name)
    {
        for (auto scene : scenes) {
            if (scene.get_name() == name)
                return scene;
        }
        return scene_e();
    }

    //scene_e management
    void scene_manager_e::add_scene(scene_e scene)
    {
        this->scenes.push_back(scene);
        printf("Scene %s added\n", scene.get_name().c_str());
    }

    void scene_manager_e::remove_scene(scene_e scene)
    {
        scenes.erase(std::remove(scenes.begin(), scenes.end(), scene), scenes.end());
    }

    void scene_manager_e::set_current_scene(std::string name)
    {
        this->current_scene = this->get_scene(name);
        printf("Current scene set to %s\n", this->current_scene.get_name().c_str());
    }
}