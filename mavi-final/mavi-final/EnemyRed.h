#pragma once
#include "GameObject.h"
#include "Enemy.h"


class EnemyRed :
    public Enemy
{
public:
	EnemyRed(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
};

