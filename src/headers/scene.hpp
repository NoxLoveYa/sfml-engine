#pragma once

#include "engine.hpp"

namespace engine
{
    class scene
    {

    };

    class scene_manager
    {
        public:
            //functions
            void render(sf::RenderWindow &render_window);

            void add_scene(scene scene);

            void remove_scene(scene scene);

            void set_current_scene(scene scene);

            scene get_current_scene(); 

        private:
            //variables
            std::vector<scene> scenes;
            scene current_scene;
    };
}