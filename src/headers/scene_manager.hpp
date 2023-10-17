#pragma once

#include "engine.hpp"

namespace engine
{
    class scene_manager_e
    {
        public:
            //constructors
            scene_manager_e()
            {
                this->current_scene = scene_e();
            }

            //functions
            void render(window_e &window);

            void add_rigid_body(rigid_body_e rigid_body)
            {
                this->current_scene.add_rigid_body(rigid_body);
            }

            void add_scene(scene_e scene);

            void remove_scene(scene_e scene);

            void set_current_scene(std::string name);

            scene_e get_current_scene()
            {
                return this->current_scene;
            }

            scene_e get_scene(std::string name)
            {
                for (auto scene : scenes) {
                    if (scene.get_name() == name)
                        return scene;
                }
                return scene_e();
            }

            std::vector<scene_e> &get_scenes()
            {
                return this->scenes;
            }

        private:
            //variables
            std::vector<scene_e> scenes;
            scene_e current_scene;
    };
}