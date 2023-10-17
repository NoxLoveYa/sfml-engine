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
                this->set_render_function(render_function);
            }

            scene_e(std::string name, std::function<void(scene_e &, sf::RenderWindow &)> render_function, std::function<void(scene_e &, window_e &window)> update_function)
            {
                this->name = name;
                this->set_render_function(render_function);
                this->set_update_function(update_function);
            }

            scene_e(std::string name, std::function<void(scene_e &, sf::RenderWindow &)> render_function, std::function<void(scene_e &, window_e &window)> update_function,
            std::function<void(scene_e &)> load_function)
            {
                this->name = name;
                this->set_render_function(render_function);
                this->set_update_function(update_function);
                this->set_load_function(load_function);
            }

            scene_e(std::string name, std::function<void(scene_e &, sf::RenderWindow &)> render_function, std::function<void(scene_e &, window_e &window)> update_function,
            std::function<void(scene_e &)> load_function, std::function<void(scene_e &)> clear_function)
            {
                this->name = name;
                this->set_render_function(render_function);
                this->set_update_function(update_function);
                this->set_load_function(load_function);
                this->set_clear_function(clear_function);
            }

            //functions
            rigid_body_e *add_rigid_body(rigid_body_e rigid_body)
            {
                this->rigid_bodies.push_back(rigid_body);
                return &this->rigid_bodies.back();
            }

            std::vector<rigid_body_e*> get_rigid_bodies()
            {
                std::vector<rigid_body_e*> rigid_bodies = std::vector<rigid_body_e*>();

                for (auto &rigid_body : this->rigid_bodies)
                {
                    rigid_bodies.push_back(&rigid_body);
                }
                return rigid_bodies;
            }

            void render(scene_e &scene, sf::RenderWindow &render_window)
            {
                this->render_function(scene, render_window);
            }
            void update(scene_e &scene, window_e &window)
            {
                this->update_function(scene, window);
            }

            void load(scene_e &scene)
            {
                this->load_function(scene);
            }
            void clear(scene_e &scene)
            {
                this->clear_function(scene);
            }

            void set_render_function(std::function<void(scene_e &, sf::RenderWindow &)> func)
            {
                this->render_function = func;
            }

            void set_update_function(std::function<void(scene_e &, window_e &)> func)
            {
                this->update_function = func;
            }

            void set_load_function(std::function<void(scene_e &)> func)
            {
                this->load_function = func;
            }

            void set_clear_function(std::function<void(scene_e &)> func)
            {
                this->clear_function = func;
            }

            std::function<void(scene_e &)> get_load_function()
            {
                return this->load_function;
            }

            std::string get_name();

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

            std::function<void(scene_e &, sf::RenderWindow &)> render_function = nullptr;
            std::function<void(scene_e &, window_e &)> update_function = nullptr;
            std::function<void(scene_e &)> load_function = nullptr;
            std::function<void(scene_e &)> clear_function = nullptr;
    };
}