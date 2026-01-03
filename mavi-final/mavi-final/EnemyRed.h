#pragma once
#include "GameObject.h"
#include "Enemy.h"


class EnemyRed :
    public GameObject, public Enemy
{
private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyRed(sf::Vector2f startPosition);
	void Update(float dt) override;
	sf::Sprite Draw() override;
	void OnCollision(GameObject* other) override;
};

