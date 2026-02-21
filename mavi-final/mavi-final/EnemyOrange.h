#pragma once
#include "GameObject.h"
#include "Enemy.h"


class EnemyOrange :
	public Enemy
{
private:
	enum class MovementState
	{
		Forward,
		Backward,
		EndOfCicle,
	};
	MovementState m_state;

public:
	EnemyOrange(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
};