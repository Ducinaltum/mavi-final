#pragma once
#include "GameObject.h"
class PlayerShip :
    public GameObject
{
private:
	float m_speed;
	float m_maxSpeed;
	float m_sqrdMaxSpeed;
	float m_friction;
	float m_shootCooldown;
	float m_actualShootCooldown;
	sf::Vector2f m_velocity;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	PlayerShip();
	void Update(float dt);
	sf::FloatRect GetCollider();
	sf::Sprite Draw();
};

