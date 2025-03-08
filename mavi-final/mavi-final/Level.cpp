#include "Level.h"

Level* Level::m_activeLevel = nullptr;

void Level::AddGameObject(GameObject obj)
{
	m_gameObjects.push_back(obj);
}

Level::Level()
{
	m_activeLevel = this;
}

void Level::ProcessPhysics()
{
	for (int i = 0; i < m_physicsObjects.size(); i++)
	{
	}
}

void Level::UpdateBehaviours(float dt)
{
	for (int i = 0; i < m_behaviours.size(); i++)
	{
		m_behaviours[i].Update(dt);
	}
}

Sprite Level::DrawObjects()
{
	for (int i = 0; i < m_renderers.size(); i++)
	{
		m_renderers[i].Draw();
	}
	Sprite s;
	return s;
}

Level* Level::GetActiveLevel()
{
	return m_activeLevel;
}

void Level::AddComponent(PhysicsObject component)
{
	m_physicsObjects.push_back(component);
}

void Level::AddComponent(Behaviour component)
{
	m_behaviours.push_back(component);
}

void Level::AddComponent(Renderer component)
{
	m_renderers.push_back(component);
}
