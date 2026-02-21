#include "EnemyBlue.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "AudioController.cpp"
#include "ImagesController.cpp"


EnemyBlue::EnemyBlue(sf::Vector2f startPosition, GameObject* playerShip, float health) :
	Enemy(health)
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

//En su update, este enemigo busca posicionarse frente a la nave del jugador
void EnemyBlue::Update(float dt)
{
	m_velocity.y = (m_position.y - m_playerShip->GetPosition().y);
	m_position -= m_velocity * dt;

	if (m_position.x < 0 - m_sprite.getGlobalBounds().width)
	{
		m_isActive = false;
	}
}