#include "EnemyRed.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "AudioController.cpp"
#include "ImagesController.cpp"

EnemyRed::EnemyRed(sf::Vector2f startPosition, GameObject* playerShip, float health) :
	Enemy(health)
{
	m_playerShip = playerShip;
	m_velocity.x = 100.0f;
	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/Enemigo1.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale(96, *t);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + startPosition.x;
	m_position.y = startPosition.y - (m_sprite.getGlobalBounds().height / 2);
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}


void EnemyRed::Update(float dt)
{
	m_position -= m_velocity * dt;
	if (m_position.x < 0 - m_sprite.getGlobalBounds().width)
	{
		m_isActive = false;
	}
}
