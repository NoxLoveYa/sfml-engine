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

    void rigid_body_e::update(float delta_time, scene_e *scene)
    {
        sf::Vector2f move_vector = this->velocity * delta_time;

        if (this->is_colliding(move_vector, scene->get_rigid_bodies())) {
            //todo calculate move vector to not collide but still move as much as possible
            move_vector = sf::Vector2f(0.0f, 0.0f);
            this->velocity = sf::Vector2f(0.0f, 0.0f);
        } else {
            velocity /= this->friction;
        }

        this->set_position(this->position + move_vector);
    }

    std::vector<rigid_body_e*> rigid_body_e::get_colliding_bodies(std::vector<rigid_body_e*> bodies)
    {
        std::vector<rigid_body_e*> colliding_bodies = std::vector<rigid_body_e*>();

        for (auto &body : bodies)
        {
            if (body != this && body->can_collide)
            {
                if (this->draw_shape->getGlobalBounds().intersects(body->draw_shape->getGlobalBounds()))
                {
                    colliding_bodies.push_back(body);
                }
            }
        }
        return colliding_bodies;
    }
}