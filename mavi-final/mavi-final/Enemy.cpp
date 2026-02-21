#include "Enemy.h"
#include "Explotion.h"
#include "ObjectPool.cpp"
#include "AudioController.cpp"
#include "PlayerShip.h"

/// <summary>
/// Esta es la clase base que vamos a usar para generar a los enemigos,
/// Particularmente Draw y OnColision son los métodos que más interesa compartir.
/// </summary>
/// <param name="startHealth"></param>
Enemy::Enemy(float startHealth) : GameObject(), m_velocity(), m_sprite(), m_health(startHealth)
{
	m_playerShip = nullptr;
}

float Enemy::GetHealthStatus()
{
    return m_health.GetStatus();
}

void Enemy::OnCollision(GameObject* other)
{
	//Administrar la colisión con proyectiles
	if (Bullet* b = dynamic_cast<Bullet*>(other))
	{
		//No todas las naves enemigas tienen el mismo valor del salud
		m_health.RecieveDamage(b->GetDamage());
		AudioController::Instance().PlaySFX(AudioController::SFX::EXPLOTION);
		if (m_health.IsDead())
		{
			m_isActive = false;
			Explode();
			if (PlayerShip* playerShip = dynamic_cast<PlayerShip*>(m_playerShip))
			{
				//El jugador suma puntos
				playerShip->AddScore(10);
			}
		}
	}
	//Administrar la colisión con la nave del jugador
	else if (PlayerShip* p = dynamic_cast<PlayerShip*>(other))
	{
		m_health.RecieveDamage(25.0f);
		if (m_health.IsDead())
		{
			//Destrucción por choque con jugador no suma puntos
			m_isActive = false;
			Explode();
		}
	}
}

void Enemy::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
}

void Enemy::Explode()
{
	//Usamos una pool para obtener los enemigos
	Explotion* e = ObjectPool<Explotion>::Instance().GetElement();
	if (e != nullptr)
	{
		e->Activate(m_position);
		e->SetSize(m_sprite.getGlobalBounds().width);
	}
}
