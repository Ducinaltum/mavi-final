#include "Extensions.h"

namespace Extensions
{
    float SqrdMagnitude(const sf::Vector2f& v)
    {
        return v.x * v.x + v.y * v.y;
    }

    float GetTargetScale(float targetWidth, sf::Texture& texture)
    {
        return targetWidth / (float)texture.getSize().x;
    }

    float Lerp(float a, float b, float t)
    {
        return a + (b - a) * t;
    }

    bool Approximately(float a, float b, float epsilon)
    {
        return std::fabs(a - b) < epsilon;
    }
}