#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once

class GameObject
{
protected:
	bool m_isActive;
	sf::Vector2f m_position;
	sf::Vector2f m_scale;
	std::vector<sf::FloatRect> m_colliders;

public:
	GameObject();
	virtual void Update(float dt) = 0;
	virtual std::vector<sf::FloatRect> GetColliders() { return m_colliders; }
	virtual void OnCollision(GameObject * other) {};
	virtual sf::Sprite Draw() = 0;
	bool GetIsActive() { return m_isActive; }
	sf::Vector2f GetPosition() { return m_position; }
};

