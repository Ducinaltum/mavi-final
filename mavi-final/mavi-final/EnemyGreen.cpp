#include "EnemyGreen.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"

//Testing ctor
EnemyGreen::EnemyGreen(float targetWidth, float startHealth) :
	GameObject(), Enemy(startHealth), m_velocity(), m_texture(), m_sprite()
{
	m_verticalAmplitude = 100.0f;
	m_cicleSpeed = 5.0f;
	m_cicleSpeedMultiplier = 1 / m_cicleSpeed;
	m_velocity.x = 100.0f;
	m_eTime = 0;
	m_texture.loadFromFile("assets/gameplay/Enemigo2.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = (float)TARGET_WIDTH;
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2) - 200;
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

EnemyGreen::EnemyGreen(sf::Vector2f startPosition) :
	GameObject(), Enemy(10.0), m_velocity(), m_texture(), m_sprite()
{
	m_verticalAmplitude = 100.0f;
	m_cicleSpeed = 5.0f;
	m_cicleSpeedMultiplier = 1 / m_cicleSpeed;
	m_velocity.x = 100.0f;
	m_eTime = 0;
	m_texture.loadFromFile("assets/gameplay/Enemigo2.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(96, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = (float)TARGET_WIDTH;
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2) - 200;
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyGreen::Update(float dt)
{
	m_velocity.y = m_verticalAmplitude * sin(m_eTime);

	m_position -= m_velocity * dt;
	m_eTime += m_cicleSpeedMultiplier * PI * 2.0f * dt;
}

sf::Sprite EnemyGreen::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}

void EnemyGreen::OnCollision(GameObject* other)
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