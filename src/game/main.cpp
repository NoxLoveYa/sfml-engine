//main to test the p100 code
#include "./headers/game.hpp"

int main(void)
{
    using namespace engine;

    window_e window("My SFML engine !!!", 60, true);
    
    scene_manager_e *scene_manager = window.get_scene_manager();
    scene_manager->add_scene(scene_e(main_scene::name, main_scene::render, main_scene::update, main_scene::load));

    scene_manager->set_current_scene(main_scene::name);

    while (window.opened) {
        window.clear();
        window.render();
    }
    return 0;
}