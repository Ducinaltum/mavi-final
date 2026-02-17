#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyBlue :
    public GameObject, public Enemy
{
public:
	EnemyBlue(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
	void Draw(sf::RenderTexture& rt) override;
	void OnCollision(GameObject* other) override;
};