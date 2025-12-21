#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once
namespace Extensions
{
	float SqrdMagnitude(const sf::Vector2f& v);
	float GetTargetScale(float targetWidth, sf::Texture& texture);
	float Lerp(float a, float b, float t);
};

