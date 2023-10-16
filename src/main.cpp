//main to test the p100 code

#include "headers/engine.hpp"

int main(void)
{
    using namespace engine;

    window window(800, 600, "My SFML engine !!!");
    
    while (window.opened) {
        window.clear();
        window.render();
    }
    return 0;
}