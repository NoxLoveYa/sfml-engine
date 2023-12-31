#pragma once

#include "engine.hpp"

namespace engine
{
    class window_e
    {
        public:
            //variables
            bool opened = true;
            
            float delta_time = 0.0f;

            sf::RenderWindow render_window;

            //constructors
            window_e(int width, int height)
            {
                this->width = width;
                this->height = height;
                this->init();
            }

            window_e(std::string title)
            {
                this->title = "My SMFL engine !!!";
                this->init();
            }
            
            window_e(std::string title, int framerate, bool fullscreen)
            {
                this->title = title;
                this->framerate = framerate;
                std::vector<sf::VideoMode> video_mode = sf::VideoMode::getFullscreenModes();
                if (video_mode.size() > 0)
                {
                    this->render_window.create(video_mode[0], this->title, sf::Style::Fullscreen);
                    this->render_window.setFramerateLimit(this->framerate);
                }
            }

            window_e(int width, int height, std::string title)
            {
                this->width = width;
                this->height = height;
                this->title = title;
                this->init();
            }

            window_e(int width, int height, std::string title, int framerate)
            {
                this->width = width;
                this->height = height;
                this->title = title;
                this->framerate = framerate;
                this->init();
            }

            void init()
            {
                this->render_window.create(sf::VideoMode(this->width, this->height), this->title);
                this->render_window.setFramerateLimit(this->framerate);
            }

            //functions
            scene_manager_e* get_scene_manager()
            {
                return &(this->scene_manager);
            }

            void set_framerate(int framerate);

            void clear();

            void render();

        private:
            //variables
            sf::Clock delta_timer = sf::Clock();

            scene_manager_e scene_manager;

            //base variables
            int width = 800;
            int height = 600;
            std::string title = "My SMFL engine !!!";

            //game variables

            //sfml variables
            int framerate = 60;
    };
}