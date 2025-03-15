#include "EnemyBlue.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"


EnemyBlue::EnemyBlue(float targetWidth, float startHealth) :
	GameObject(), Enemy(startHealth), m_velocity(), m_texture(), m_sprite()
{
	m_velocity.x = 100.0f;
	m_texture.loadFromFile("assets/gameplay/Enemigo4.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + 200;
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2) - 200;
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyBlue::Update(float dt)
{
	m_position -= m_velocity * dt;
}

sf::Sprite EnemyBlue::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}

void EnemyBlue::OnCollision(GameObject* other)
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