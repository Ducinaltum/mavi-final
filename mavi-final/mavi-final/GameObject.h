#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#pragma once

class GameObject
{
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_scale;

public:
	GameObject();
	virtual void Update(float dt) = 0;
	virtual sf::FloatRect GetCollider() = 0;
	virtual sf::Sprite Draw() = 0;
};

