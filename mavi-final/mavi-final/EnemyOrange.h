#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyOrange :
	public GameObject, public Enemy
{
private:
	GameObject* m_playerShip;
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyOrange(sf::Vector2f startPosition, GameObject* playerShip);
	void Update(float dt) override;
	sf::Sprite Draw() override;
	void OnCollision(GameObject* other) override;
};