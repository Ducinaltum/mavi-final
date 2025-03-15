#include "Gameplay.h"
#include <iostream>


Gameplay::Gameplay()
{
	GameObject* playerShip = new PlayerShip(50);
	m_gameObjects.push_back(playerShip);
	for (int i = 0; i < 10; i++)
	{
		GameObject* bullet = new Bullet(25);
		m_gameObjects.push_back(bullet);
	}
	EnemyRed* enemy = new EnemyRed(128);
	m_gameObjects.push_back(enemy);

	std::cout << m_gameObjects.size() << std::endl;
}

void Gameplay::ProcessCollisions()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		for (int j = 0; j < m_gameObjects.size(); j++)
		{
			GameObject* other = m_gameObjects[j];
			std::vector<sf::FloatRect> currentColliders = current->GetColliders();
			std::vector<sf::FloatRect> otherColliders = other->GetColliders();
			for (sf::FloatRect rect : currentColliders)
			{
				bool hasCollided = false;
				for (sf::FloatRect otherRect : otherColliders)
				{
					if (rect.intersects(otherRect))
					{
						std::cout << "COLLISION" << std::endl;
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
