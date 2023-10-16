#include "../headers/engine.hpp"

namespace engine
{
    namespace shape
    {
        void clone_shape(sf::Shape *shape, sf::Shape *shape2)
        {
            shape2->setFillColor(shape->getFillColor());
            shape2->setOutlineColor(shape->getOutlineColor());
            shape2->setOutlineThickness(shape->getOutlineThickness());
            shape2->setPosition(shape->getPosition());
            shape2->setRotation(shape->getRotation());
            shape2->setScale(shape->getScale());
            shape2->setOrigin(shape->getOrigin());
        }
    }
}