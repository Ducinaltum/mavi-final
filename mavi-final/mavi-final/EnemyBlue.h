#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyBlue :
    public GameObject, public Enemy
{
private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyBlue(float targetWidth, float startHealth);
	void Update(float dt) override;
	sf::Sprite Draw() override;
	void OnCollision(GameObject* other) override;
};