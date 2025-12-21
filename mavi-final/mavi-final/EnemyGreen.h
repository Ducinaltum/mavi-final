#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyGreen :
    public GameObject, public Enemy
{
private:
	float m_verticalAmplitude;
	float m_cicleSpeed;
	float m_cicleSpeedMultiplier;
	float m_eTime;
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyGreen(float targetWidth, float startHealth);
	EnemyGreen(sf::Vector2f startPosition);
	void Update(float dt) override;
	sf::Sprite Draw() override;
	void OnCollision(GameObject* other) override;
};