#pragma once

#include "engine.hpp"

namespace engine
{
    class window
    {
        public:
            //base variables
            bool opened = true;
            
            int width = 800;
            int height = 600;
            std::string title = "My SMFL engine !!!";

            //game variables
            float delta_time = 0.0f;

            //sfml variables
            int framerate = 60;

            sf::RenderWindow render_window;

            //constructors
            window(int width, int height)
            {
                this->width = width;
                this->height = height;
                this->init();
            }

            window(std::string title)
            {
                this->title = "My SMFL engine !!!";
                this->init();
            }

            window(int width, int height, std::string title)
            {
                this->width = width;
                this->height = height;
                this->title = title;
                this->init();
            }

            window(int width, int height, std::string title, int framerate)
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
            void set_framerate(int framerate);

            void clear();

            void render();

        private:
            //variables
            sf::Clock delta_timer = sf::Clock();
            //functions
    };
}