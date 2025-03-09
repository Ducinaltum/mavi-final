#include "Extensions.h"

namespace Extensions
{
    float SqrdMagnitude(const sf::Vector2f& v)
    {
        return v.x * v.x + v.y * v.y;
    }

    float GetTargetScale(float targetWidth, sf::Texture& texture)
    {
        return targetWidth / (float) texture.getSize().x;
    }
}