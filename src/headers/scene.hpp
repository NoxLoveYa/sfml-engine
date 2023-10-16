#pragma once

#include "engine.hpp"

namespace engine
{
    class scene_e
    {
        public:
            //constructors
            scene_e()
            {
                this->name = "null";
            }

            scene_e(std::string name)
            {
                this->name = name;
            }

            scene_e(std::string name, std::function<void(sf::RenderWindow &)> render_function)
            {
                this->name = name;
                this->render_function = render_function;
            }

            scene_e(std::string name, std::function<void(sf::RenderWindow &)> render_function, std::function<void(window_e &window)> update_function)
            {
                this->name = name;
                this->render_function = render_function;
                this->update_function = update_function;
            }

            //functions
            void render(sf::RenderWindow &render_window)
            {
                this->render_function(render_window);
            }
            void update(window_e &window)
            {
                this->update_function(window);
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
            std::string name;

            std::function<void(sf::RenderWindow &)> render_function;
            std::function<void(window_e &)> update_function;
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

            void add_scene(scene_e scene);

            void remove_scene(scene_e scene);

            void set_current_scene(std::string name);

            scene_e get_current_scene();

            scene_e get_scene(std::string name);

            std::vector<scene_e> &get_scenes()
            {
                return this->scenes;
            }

            void print_scenes()
            {
                for (auto scene : this->scenes) {
                    printf("Scene %s\n", scene.get_name().c_str());
                }
            }

        private:
            //variables
            std::vector<scene_e> scenes;
            scene_e current_scene;
    };
}