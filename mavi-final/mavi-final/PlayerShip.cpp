#include "PlayerShip.h"
#include "InputHandler.h"
#include "Extensions.h"
#include <iostream>
#include "Globals.h"
#include "ObjectPool.cpp"
#include "Enemy.h"
#include "AudioController.cpp"
#include "ImagesController.cpp"

PlayerShip::PlayerShip(float targetWidth, float startHealth) :
	GameObject(), m_health(startHealth), m_velocity(), m_sprite()
{
	m_score = 0;
	m_speed = 0.0005f;
	m_friction = 0.998f;
	m_maxSpeed = 0.1f;
	m_sqrdMaxSpeed = m_maxSpeed * m_maxSpeed;
	m_shootCooldown = 0.5f;
	m_actualShootCooldown = 1;

	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/ship.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale(targetWidth, *t);
	m_sprite.setScale(scale, scale);
	m_bulletsSpawnPoint.x = targetWidth;
	m_bulletsSpawnPoint.y = (t->getSize().y * scale) / 2;
	m_position.x = m_sprite.getGlobalBounds().width; //One ship to the border of screen
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2);
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void PlayerShip::Update(float dt)
{
	Vector2f movement = Input::InputHandler::Movement1 * m_speed;
	m_velocity += movement;
	m_velocity *= m_friction;

	float sqrdVelocityMagnitude = Extensions::SqrdMagnitude(m_velocity);
	if (sqrdVelocityMagnitude > m_sqrdMaxSpeed)
	{
		float ratio = m_sqrdMaxSpeed / sqrdVelocityMagnitude;
		m_velocity *= ratio;
	}
	if (Input::InputHandler::Action1.GetButtonDown()
		&& m_actualShootCooldown > m_shootCooldown)
	{
		m_actualShootCooldown = 0;
		AudioController::Instance().PlaySFX(AudioController::SFX::SHOT);
		Bullet* b = ObjectPool<Bullet>::Instance().GetElement();
		if (b != nullptr)
			b->Activate(m_position + m_bulletsSpawnPoint);
		else
			std::cout << "Bullet is NULL" << std::endl;
	}


	m_position += m_velocity;

	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	else if (m_position.x > TARGET_WIDTH - m_sprite.getGlobalBounds().width)
	{
		m_position.x = (float)TARGET_WIDTH - m_sprite.getGlobalBounds().width;
	}

	if (m_position.y < 0)
	{
		m_position.y = 0;
	}
	else if (m_position.y > TARGET_HEIGHT - m_sprite.getGlobalBounds().height)
	{
		m_position.y = (float)TARGET_HEIGHT - m_sprite.getGlobalBounds().height;
	}

	bool cooldownCompletedOnFrame = m_actualShootCooldown < m_shootCooldown;
	m_actualShootCooldown += dt;
	if (cooldownCompletedOnFrame && m_actualShootCooldown > m_shootCooldown)
	{
		AudioController::Instance().PlaySFX(AudioController::SFX::RELOAD);		
	}
}


void PlayerShip::OnCollision(GameObject* other)
{
	if (Enemy* e = dynamic_cast<Enemy*>(other))
	{
		AudioController::Instance().PlaySFX(AudioController::SFX::COLLISION);
		m_health.RecieveDamage(25.0f);
		if (m_health.IsDead())
		{
			m_isActive = false;
		}
	}
}

void PlayerShip::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
}

Health * PlayerShip::GetHealth()
{
	return &m_health;
}

float PlayerShip::GetCooldownStatus()
{
	float cooldownRatio = m_actualShootCooldown / m_shootCooldown;
	return cooldownRatio > 1 ? 1 : cooldownRatio;
}

void PlayerShip::AddScore(int score)
{
	m_score += score;
}

int PlayerShip::GetScore()
{
	return m_score;
}