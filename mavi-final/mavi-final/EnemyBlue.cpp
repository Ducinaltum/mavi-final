#include "EnemyBlue.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "AudioController.cpp"
#include "ImagesController.cpp"


EnemyBlue::EnemyBlue(sf::Vector2f startPosition, GameObject* playerShip, float health) :
	GameObject(), Enemy(health)
{
	m_playerShip = playerShip;

	m_velocity.x = 100.0f;
	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/Enemigo4.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale(96, *t);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + startPosition.x;
	m_position.y = startPosition.y - (m_sprite.getGlobalBounds().height / 2);
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyBlue::Update(float dt)
{
	m_velocity.y = (m_position.y - m_playerShip->GetPosition().y);
	m_position -= m_velocity * dt;

	if (m_position.x < 0 - m_sprite.getGlobalBounds().width)
	{
		m_isActive = false;
	}
}

void EnemyBlue::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
}

void EnemyBlue::OnCollision(GameObject* other)
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