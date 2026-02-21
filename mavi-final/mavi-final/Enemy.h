#pragma once
#include "Health.h"
#include "GameObject.h"

class Enemy: public GameObject
{
protected:
	Health m_health;
	GameObject* m_playerShip;
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Sprite m_sprite;
public:
	Enemy(float startHealth);
	void Draw(sf::RenderTexture& rt) override;
	void OnCollision(GameObject* other) override;
	float GetHealthStatus();
	void Explode();
};

