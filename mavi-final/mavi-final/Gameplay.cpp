#include "Gameplay.h"
#include <iostream>
#include "EnemyBlue.h"
#include "EnemyPurple.h"

Gameplay::Gameplay()
{
	m_waveIndex = 0;
	m_playerShip = new PlayerShip(50, 100.f);
	GameObject* playerShip = m_playerShip;
	m_gameObjects.push_back(playerShip);
	for (int i = 0; i < 10; i++)
	{
		GameObject* bullet = new Bullet(25);
		m_gameObjects.push_back(bullet);
	}
	m_wave = new Wave(5, m_playerShip);
	for (int i = 0; i < m_wave->GetObjects().size(); i++)
	{
		m_gameObjects.push_back(m_wave->GetObjects()[i]);
	}
	m_hud = new HUD(m_playerShip, m_wave);
	
}

void Gameplay::ProcessCollisions()
{
	int checks = 0;
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			for (int j = i + 1; j < m_gameObjects.size(); j++)
			{
				GameObject* other = m_gameObjects[j];
				if (other->GetIsActive())
				{
					std::vector<sf::FloatRect> currentColliders = current->GetColliders();
					std::vector<sf::FloatRect> otherColliders = other->GetColliders();
					for (sf::FloatRect rect : currentColliders)
					{
						bool hasCollided = false;
						rect.left = current->GetPosition().x;
						rect.top = current->GetPosition().y;
						for (sf::FloatRect otherRect : otherColliders)
						{
							checks++;
							otherRect.left = other->GetPosition().x;
							otherRect.top = other->GetPosition().y;
							if (rect.intersects(otherRect))
							{
								hasCollided = true;
								break;
							}
						}
						if (hasCollided)
						{
							current->OnCollision(other);
							other->OnCollision(current);
							break;
						}
					}
				}
			}
		}
	}
}

void Gameplay::Update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			current->Update(dt);
		}
	}

	if (m_wave->IsCompleted())
	{
		m_waveIndex++;
		for (int i = 0; i < m_gameObjects.size(); )
		{
			bool isEnemy = dynamic_cast<Enemy*>(m_gameObjects[i]);
			if (isEnemy)
			{
				delete m_gameObjects[i];
				if (i != m_gameObjects.size() - 1)
					m_gameObjects[i] = m_gameObjects.back();
				m_gameObjects.pop_back();
			}
			else
			{
				++i;
			}
		}
		m_wave->SpawnNextWave();
		if (m_wave->RemainsAnyWave())
		{
			for (int i = 0; i < m_wave->GetObjects().size(); i++)
			{
				m_gameObjects.push_back(m_wave->GetObjects()[i]);
			}
		}
		else
		{
			std::cout << "EOG" << std::endl;
		}
	}
	m_hud->Update(dt);
}

void Gameplay::Draw(sf::RenderTexture& window)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			window.draw(current->Draw());
		}
	}
	m_hud->Draw(window);
}
