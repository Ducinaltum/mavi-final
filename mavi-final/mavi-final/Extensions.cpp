#include "Extensions.h"

namespace Extensions
{
    float SqrdMagnitude(const sf::Vector2f& v)
    {
        return v.x * v.x + v.y * v.y;
    }

}