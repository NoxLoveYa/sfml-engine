#pragma once

#include "engine.hpp"

namespace engine
{
    class rigid_body_e
    {
        public:
            rigid_body_e(void)
            {
                this->position = sf::Vector2f(0, 0);
                this->velocity = sf::Vector2f(0, 0);
                this->mass = 0;
                this->draw_shape = nullptr;
            }

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;
                this->draw_shape = nullptr;
            }

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass, sf::Shape *draw_shape)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;

                this->draw_shape = (sf::Shape*)(sizeof(sf::Shape));
                engine::shape::clone_shape(draw_shape, this->draw_shape);
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

        private:
            sf::Vector2f position;
            sf::Vector2f velocity;
            float mass;
            sf::Shape *draw_shape;
    };
}