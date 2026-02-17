#include "EnemyOrange.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include <cmath>  // std::lerp
#include <iostream>
#include "AudioController.cpp"
#include "ImagesController.cpp"

EnemyOrange::EnemyOrange(sf::Vector2f startPosition, GameObject* playerShip, float health) :
	GameObject(), Enemy(health)
{
	m_playerShip = playerShip;
	m_state = MovementState::Forward;

	m_velocity.x = 100.0f;
	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/Enemigo3.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale(96, *t);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + startPosition.x;
	m_position.y = startPosition.y - (m_sprite.getGlobalBounds().height / 2);
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyOrange::Update(float dt)
{
	if (m_state == MovementState::Backward)
	{
		if (m_position.y < 10 || (m_position.y + m_sprite.getGlobalBounds().height) > (TARGET_HEIGHT - 10))
		{
			m_state = MovementState::EndOfCicle;
			m_velocity.x = 100.0f;
			m_velocity.y = 0.f;
		}
	}
	else if (m_state == MovementState::Forward)
	{
		if (m_position.x < 100)
		{
			m_state = MovementState::Backward;
			m_velocity.x = -250.0f;
			m_velocity.y = 150.f;
			m_velocity.y *= m_position.y < (TARGET_HEIGHT / 2) ? -1 : 1;
		}
	}
	m_position -= m_velocity * dt;
	if (m_position.x < 0 - m_sprite.getGlobalBounds().width)
	{
		m_isActive = false;
	}
}

void EnemyOrange::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
}

void EnemyOrange::OnCollision(GameObject* other)
{
	if (Bullet* b = dynamic_cast<Bullet*>(other))
	{
		m_health.RecieveDamage(b->GetDamage());
		AudioController::Instance().PlaySFX(AudioController::SFX::EXPLOTION);
		if (m_health.IsDead())
		{
			m_isActive = false;
			if (PlayerShip* playerShip = dynamic_cast<PlayerShip*>(m_playerShip))
			{
				playerShip->AddScore(10);
			}
		}
	}
	else if (PlayerShip* p = dynamic_cast<PlayerShip*>(other))
	{
		m_health.RecieveDamage(25.0f);
		if (m_health.IsDead())
		{
			m_isActive = false;
		}
	}
}

