#include "Component.h"
#include <SFML/Graphics/Rect.hpp>

#pragma once
class PhysicsObject : Component
{
public:
	sf::FloatRect GetCollider();
};

