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

            //functions
            void render(sf::RenderWindow &render_window)
            {
                this->render_function(render_window);
            }
            void update()
            {
                this->update_function();
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
            std::function<void()> update_function;
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
            void render(sf::RenderWindow &render_window);

            void add_scene(scene_e scene);

            void remove_scene(scene_e scene);

            void set_current_scene(scene_e scene);

            scene_e get_current_scene(); 

        private:
            //variables
            std::vector<scene_e> scenes;
            scene_e current_scene;
    };
}