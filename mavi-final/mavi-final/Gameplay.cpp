#include "Gameplay.h"

Gameplay::Gameplay()
{
	GameObject* playerShip = new PlayerShip();
	m_gameObjects.push_back(playerShip);
}

void Gameplay::ProcessCollisions()
{
}

void Gameplay::Update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update(dt);
	}
}

void Gameplay::Draw(sf::RenderTexture& window)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		window.draw(m_gameObjects[i]->Draw());
	}
}
