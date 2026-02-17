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

public:
	EnemyGreen(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
	void Draw(sf::RenderTexture& rt) override;
	void OnCollision(GameObject* other) override;
};