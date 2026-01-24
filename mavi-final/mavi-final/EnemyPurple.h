#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyPurple :
    public GameObject, public Enemy
{
private:
	enum class MovementState
	{
		Traveling,
		DoubleSineMovement,
	};
	GameObject* m_playerShip;
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	MovementState m_state;
	float m_verticalAmplitude;
	float m_horizontallAmplitude;
	float m_verticalCicleSpeed;
	float m_horizontalCicleSpeed;
	float m_verticalCicleSpeedMultiplier;
	float m_horizontalCicleSpeedMultiplier;
	float m_verticalTime;
	float m_horizontalTime;

public:
	EnemyPurple(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
	sf::Sprite Draw() override;
	void OnCollision(GameObject* other) override;
};