#include "EnemyOrange.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include <cmath>  // std::lerp
#include <iostream>

EnemyOrange::EnemyOrange(sf::Vector2f startPosition, GameObject* playerShip) :
	GameObject(), Enemy(10.0), m_velocity(), m_texture(), m_sprite()
{
	m_playerShip = playerShip;

	m_velocity.x = 100.0f;
	m_texture.loadFromFile("assets/gameplay/Enemigo3.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(96, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + startPosition.x;
	m_position.y = startPosition.y - (m_sprite.getGlobalBounds().height / 2);
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyOrange::Update(float dt)
{
	m_velocity.y = (m_position.y - m_playerShip->GetPosition().y);
	//std::cout << "position.y: " << m_position.y << "; playerShip.y: " << m_playerShip->GetPosition().y << "; velocity.y: " << m_velocity.y << "; dt: " << dt << std::endl;
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

