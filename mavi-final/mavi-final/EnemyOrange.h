#pragma once
#include "GameObject.h"
#include "Enemy.h"


class EnemyOrange :
	public GameObject, public Enemy
{
private:
	enum class MovementState
	{
		Forward,
		Backward,
		EndOfCicle,
	};
	GameObject* m_playerShip;
	MovementState m_state;
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyOrange(sf::Vector2f startPosition, GameObject* playerShip, float health);
	void Update(float dt) override;
	void Draw(sf::RenderTexture& rt) override;
	void OnCollision(GameObject* other) override;
};