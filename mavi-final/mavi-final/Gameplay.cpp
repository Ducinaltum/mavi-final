#include "Gameplay.h"
#include <iostream>
#include "EnemyBlue.h"
#include "EnemyPurple.h"


Gameplay::Gameplay()
{
	GameObject* playerShip = new PlayerShip(50, 100.f);
	m_gameObjects.push_back(playerShip);
	for (int i = 0; i < 10; i++)
	{
		GameObject* bullet = new Bullet(25);
		m_gameObjects.push_back(bullet);
	}
	EnemyRed* enemyRed = new EnemyRed(128, 10.0f);
	m_gameObjects.push_back(enemyRed);
	EnemyOrange* enemyOrange = new EnemyOrange(128, 10.0f);
	m_gameObjects.push_back(enemyOrange);
	EnemyGreen* enemyGreen = new EnemyGreen(128, 10.0f);
	m_gameObjects.push_back(enemyGreen);
	EnemyBlue* enemyBlue = new EnemyBlue(128, 10.0f);
	m_gameObjects.push_back(enemyBlue);
	EnemyPurple* enemyPurple = new EnemyPurple(128, 10.0f);
	m_gameObjects.push_back(enemyPurple);

	std::cout << m_gameObjects.size() << std::endl;
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
	std::cout << checks << std::endl;
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
}
