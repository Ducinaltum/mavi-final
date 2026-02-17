#pragma once
#include "GameObject.h"
#include "Enemy.h"


class EnemyRed :
    public GameObject, public Enemy
{
public:
	EnemyRed(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
	void Draw(sf::RenderTexture& rt) override;
	void OnCollision(GameObject* other) override;
};

