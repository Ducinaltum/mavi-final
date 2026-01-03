#include "EnemyPurple.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"


EnemyPurple::EnemyPurple(float targetWidth, float startHealth) :
	GameObject(), Enemy(startHealth), m_velocity(), m_texture(), m_sprite()
{
	m_velocity.x = 100.0f;
	m_texture.loadFromFile("assets/gameplay/Enemigo5.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + 200;
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2) + 200;
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyPurple::Update(float dt)
{
	m_position -= m_velocity * dt;

	if (m_position.x < 0 - m_sprite.getGlobalBounds().width)
	{
		m_isActive = false;
	}
}

sf::Sprite EnemyPurple::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}

void EnemyPurple::OnCollision(GameObject* other)
{
	if (Bullet* b = dynamic_cast<Bullet*>(other))
	{
		m_health.RecieveDamage(b->GetDamage());
		if (m_health.IsDead())
		{
			m_isActive = false;
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