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

            rigid_body_e(sf::Vector2f position, sf::Vector2f velocity, float mass, float friction, sf::Shape *draw_shape, bool can_collide)
            {
                this->position = position;
                this->velocity = velocity;
                this->mass = mass;
                this->friction = friction;
                this->draw_shape = draw_shape;
                this->can_collide = can_collide;
            }

            ~rigid_body_e(void)
            {
            }

            void set_position(sf::Vector2f position)
            {
                this->position = position;
                this->draw_shape->setPosition(position);
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

            void set_can_collide(bool can_collide)
            {
                this->can_collide = can_collide;
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

            bool get_can_collide(void)
            {
                return this->can_collide;
            }

            sf::FloatRect get_draw_bounds(void)
            {
                return this->draw_shape->getGlobalBounds();
            }

            void apply_force(sf::Vector2f force);
            void apply_impulse(sf::Vector2f impulse);

            bool is_colliding(sf::Vector2f move_vector, std::vector<rigid_body_e*> bodies)
            {
                if (!this->can_collide)
                    return false;
                sf::FloatRect bounds = this->draw_shape->getGlobalBounds();

                bounds.left += move_vector.x;
                bounds.top += move_vector.y;

                for (auto &body : bodies) {
                    if (body != this && bounds.intersects(body->draw_shape->getGlobalBounds()))
                        return true;
                }
                return false;
            }

            std::vector<rigid_body_e*> get_colliding_bodies(std::vector<rigid_body_e*> bodies);

            void update(float delta_time, scene_e *scene);
            void render(sf::RenderWindow &window)
            {
                window.draw(*this->draw_shape);
            }

        private:
            sf::Vector2f position = sf::Vector2f(0.f, 0.f);
            sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
            float mass = 9.8f;
            float friction = 1.1f;
            sf::Shape *draw_shape = new sf::CircleShape(50, 3);

            bool can_collide = true;
    };
}