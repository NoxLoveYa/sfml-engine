#pragma once

#include "engine.hpp"

namespace engine
{
    class scene_e
    {
        public:
            //variables
            std::vector<rigid_body_e> rigid_bodies = std::vector<rigid_body_e>();

            //constructors
            scene_e()
            {
                this->name = "null";
            }

            scene_e(std::string name)
            {
                this->name = name;
            }

            scene_e(std::string name, std::function<void(scene_e &, sf::RenderWindow &)> render_function)
            {
                this->name = name;
                this->render_function = render_function;
            }

            scene_e(std::string name, std::function<void(scene_e &, sf::RenderWindow &)> render_function, std::function<void(scene_e &, window_e &window)> update_function)
            {
                this->name = name;
                this->render_function = render_function;
                this->update_function = update_function;
            }

            //functions
            void render(scene_e &scene, sf::RenderWindow &render_window)
            {
                this->render_function(scene, render_window);
            }
            void update(scene_e &scene, window_e &window)
            {
                this->update_function(scene, window);
            }

            void load()
            {
                this->load_function();
            }
            void clear()
            {
                this->clear_function();
            }

            std::string get_name();

            void add_rigid_body(rigid_body_e rigid_body)
            {
                this->rigid_bodies.push_back(rigid_body);
            }

            //constructors

            //variables

            //overloads
            //==
            bool operator==(const scene_e &scene)
            {
                return this->name == scene.name;
            }
            //!=
            bool operator!=(const scene_e &scene)
            {
                return this->name != scene.name;
            } 

        private:
            //variables
            std::string name = "null";

            std::function<void(scene_e &, sf::RenderWindow &)> render_function;
            std::function<void(scene_e &, window_e &)> update_function;
            std::function<void()> load_function;
            std::function<void()> clear_function;
    };

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