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
		std::cout << bullet << std::endl;
	}
	std::cout << m_gameObjects.size() << std::endl;
}

void Gameplay::ProcessCollisions()
{
}

void Gameplay::Update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			//std::cout << "Active Object " << current << std::endl;
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
