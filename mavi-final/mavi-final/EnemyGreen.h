#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyGreen :
    public GameObject, public Enemy
{
private:
	GameObject* m_playerShip;
	float m_verticalAmplitude;
	float m_cicleSpeed;
	float m_cicleSpeedMultiplier;
	float m_eTime;
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyGreen(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
	sf::Sprite Draw() override;
	void OnCollision(GameObject* other) override;
};