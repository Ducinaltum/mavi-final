#include "EnemyPurple.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"


EnemyPurple::EnemyPurple(sf::Vector2f startPosition) :
	GameObject(), Enemy(10.0), m_velocity(), m_texture(), m_sprite()
{
	m_state = MovementState::Traveling;
	m_velocity.x = 100.0f;

	m_verticalAmplitude = 200.0f;
	m_horizontallAmplitude = 100.0f;
	m_verticalCicleSpeed = 7.5f;
	m_horizontalCicleSpeed = 5.0f;
	m_verticalCicleSpeedMultiplier = 1 / m_verticalCicleSpeed;
	m_horizontalCicleSpeedMultiplier = 1 / m_horizontalCicleSpeed;
	m_horizontalTime = PI /2;
	m_verticalTime = PI /2;

	m_texture.loadFromFile("assets/gameplay/Enemigo5.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(192, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + startPosition.x;
	m_position.y = startPosition.y - (m_sprite.getGlobalBounds().height / 2);

	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyPurple::Update(float dt)
{
	if (m_state == MovementState::Traveling)
	{
		if (m_position.x < (TARGET_WIDTH / 3) * 2)
		{
			m_state = MovementState::DoubleSineMovement;
		}
	}
	else
	{
		m_velocity.x = m_horizontallAmplitude * sin(m_horizontalTime);
		m_velocity.y = m_verticalAmplitude * sin(m_verticalTime);

		m_horizontalTime += m_horizontalCicleSpeedMultiplier * PI * 2.0f * dt;
		m_verticalTime += m_verticalCicleSpeedMultiplier * PI * 2.0f * dt;
	}

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