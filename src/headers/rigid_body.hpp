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

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass, sf::Shape *draw_shape)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;

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

            void apply_force(sf::Vector2f force);
            void apply_impulse(sf::Vector2f impulse);

            void update(void);
            void render(sf::RenderWindow &window)
            {
                this->draw_shape->setPosition(this->position);
                window.draw(*this->draw_shape);
            }

        private:
            sf::Vector2f position = sf::Vector2f(0, 0);
            sf::Vector2f velocity = sf::Vector2f(0, 0);
            float mass = 0;
            sf::Shape *draw_shape = nullptr;
    };
}