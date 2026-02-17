#pragma once
#include "GameObject.h"
#include "Health.h"
class PlayerShip :
    public GameObject
{
private:
	float m_speed;
	float m_maxSpeed;
	float m_sqrdMaxSpeed;
	float m_friction;
	float m_shootCooldown;
	float m_actualShootCooldown;
	int m_score;

	Health m_health;

	sf::Vector2f m_velocity;
	sf::Sprite m_sprite;

	sf::Vector2f m_bulletsSpawnPoint;
public:
	PlayerShip(float targetWidth, float startHealth);
	void Update(float dt) override;
	void OnCollision(GameObject* other) override;
	void Draw(sf::RenderTexture& rt) override;
	Health * GetHealth();
	float GetCooldownStatus();
	void AddScore(int score);
	int GetScore();
};

