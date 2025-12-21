#include "EnemyOrange.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include <cmath>  // std::lerp
#include <iostream>

EnemyOrange::EnemyOrange(float targetWidth, float startHealth, GameObject * playerShip):
	GameObject(), Enemy(startHealth), m_velocity(), m_texture(), m_sprite()
{
	m_playerShip = playerShip;
	m_velocity.x = 100.0f;
	m_texture.loadFromFile("assets/gameplay/Enemigo3.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH;
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2) + 200;
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyOrange::Update(float dt)
{
	float l = Extensions::Lerp(m_position.y, m_position.y - m_playerShip->GetPosition().y, dt);
	m_velocity.y = l;
	m_position -= m_velocity * dt;
}

sf::Sprite EnemyOrange::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}

void EnemyOrange::OnCollision(GameObject* other)
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

