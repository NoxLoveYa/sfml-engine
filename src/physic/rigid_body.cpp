#include "../headers/engine.hpp"

namespace engine
{
    void rigid_body_e::apply_force(sf::Vector2f force)
    {
        this->velocity += (force / this->mass);
    }

    void rigid_body_e::apply_impulse(sf::Vector2f impulse)
    {
        this->velocity += impulse;
    }

    void rigid_body_e::update(void)
    {
        this->position += this->velocity;
    }
}