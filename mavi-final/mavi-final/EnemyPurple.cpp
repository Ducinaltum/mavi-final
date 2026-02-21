#include "EnemyPurple.h"
#include "Globals.h"
#include "Extensions.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "AudioController.cpp"
#include "ImagesController.cpp"


EnemyPurple::EnemyPurple(sf::Vector2f startPosition, GameObject* playerShip, float health) :
	Enemy(health)
{
	m_playerShip = playerShip;
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

	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/Enemigo5.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale(192, *t);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH + startPosition.x;
	m_position.y = startPosition.y - (m_sprite.getGlobalBounds().height / 2);

	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

//En su update, este enemigo busca posicionarse a un tercio de la derecha de la pantalla
//Luego, comienza a moverse sinusoidalmente en el eje x e y en ondas no sincrónicas
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

