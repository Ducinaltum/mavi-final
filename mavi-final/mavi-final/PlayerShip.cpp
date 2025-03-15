#include "PlayerShip.h"
#include "InputHandler.h"
#include "Extensions.h"
#include <iostream>
#include "Globals.h"
#include "ObjectPool.cpp"

PlayerShip::PlayerShip(float targetWidth) : GameObject(), m_velocity(), m_texture(), m_sprite()
{
	m_speed = 0.0005f;
	m_friction = 0.998f;
	m_maxSpeed = 0.1f;
	m_sqrdMaxSpeed = m_maxSpeed * m_maxSpeed;
	m_shootCooldown = 0.5f;
	m_actualShootCooldown = -1;

	m_texture.loadFromFile("assets/gameplay/ship.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_bulletsSpawnPoint.x = targetWidth;
	m_bulletsSpawnPoint.y = (m_texture.getSize().y * scale) / 2;
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
		&& m_actualShootCooldown < 0)
	{
		std::cout << "Shoot" << std::endl;
		m_actualShootCooldown = m_shootCooldown;
		Bullet * b = ObjectPool<Bullet>::Instance().GetBullet();
		if (b != nullptr)
			b->Activate(m_position + m_bulletsSpawnPoint);
		else
			std::cout << "Bullet is NULL" << std::endl;
	}


	m_position += m_velocity;

	//sf::Vector2f pixelSize = Extensions::GetPixelSize(m_sprite);
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

	m_actualShootCooldown -= dt;
}


void PlayerShip::OnCollision(GameObject * other)
{
}

sf::Sprite PlayerShip::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}
