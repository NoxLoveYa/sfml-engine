#include "../headers/engine.hpp"

namespace engine
{
    void rigid_body_e::apply_force(sf::Vector2f force)
    {
        if (this->friction != 0.0f)
            force /= this->friction;
        this->velocity += (force);
    }

    void rigid_body_e::apply_impulse(sf::Vector2f impulse)
    {
        this->velocity += impulse;
    }

    void rigid_body_e::update(float delta_time)
    {
        this->position += (this->velocity * delta_time);
        this->velocity /= 1.1f;
    }
}