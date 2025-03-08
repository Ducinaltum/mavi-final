#include "PlayerShip.h"
#include "InputHandler.h"
#include "Extensions.h"
#include <iostream>
#include "Globals.h"

PlayerShip::PlayerShip() : GameObject(), m_velocity(), m_texture(), m_sprite()
{
	m_speed = 0.001f;
	m_friction = 0.998f;
	m_maxSpeed = 1;
	m_sqrdMaxSpeed = m_maxSpeed * m_maxSpeed;
	m_shootCooldown = 0.5f;
	m_actualShootCooldown = 0;

	m_texture.loadFromFile("assets/ship.png");
	m_sprite.setTexture(m_texture);
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
		&& m_actualShootCooldown < 0)
	{
		//Shoot
		m_actualShootCooldown = m_shootCooldown;
	}


	m_position += m_velocity;
	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	else if (m_position.x > TARGET_WIDTH - 100)
	{
		m_position.x = (float)TARGET_WIDTH - 100;
	}

	if (m_position.y < 0)
	{
		m_position.y = 0;
	}
	else if (m_position.y > TARGET_HEIGHT - 100)
	{
		m_position.y = (float)TARGET_HEIGHT - 100;
	}

	m_actualShootCooldown -= dt;
}

sf::FloatRect PlayerShip::GetCollider()
{
	return sf::FloatRect();
}

sf::Sprite PlayerShip::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}
