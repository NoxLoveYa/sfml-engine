#pragma once

#include "engine.hpp"

namespace engine
{
    class rigid_body_e
    {
        public:
            rigid_body_e(void)
            {
            }

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;
            }

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass, float friction)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;
                this->friction = friction;
            }

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass, float friction, sf::Shape *draw_shape)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;
                this->friction = friction;
                this->draw_shape = draw_shape;
            }

            ~rigid_body_e(void)
            {
            }

            void set_position(sf::Vector2f position)
            {
                this->position = position;
            }

            void set_velocity(sf::Vector2f velocity)
            {
                this->velocity = velocity;
            }

            void set_mass(float mass)
            {
                this->mass = mass;
            }

            void set_friction(float friction)
            {
                this->friction = friction;
            }

            sf::Vector2f get_position(void)
            {
                return this->position;
            }

            sf::Vector2f get_velocity(void)
            {
                return this->velocity;
            }

            float get_mass(void)
            {
                return this->mass;
            }

            float get_friction(void)
            {
                return this->friction;
            }

            void apply_force(sf::Vector2f force);
            void apply_impulse(sf::Vector2f impulse);

            void update(float delta_time);
            void render(sf::RenderWindow &window)
            {
                this->draw_shape->setPosition(this->position);
                window.draw(*this->draw_shape);
            }

        private:
            sf::Vector2f position = sf::Vector2f(0.f, 0.f);
            sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
            float mass = 9.8f;
            float friction = 1.1f;
            sf::Shape *draw_shape = new sf::CircleShape(50, 3);
    };
}