#include "GameObject.h"
#include "Level.cpp"

GameObject::GameObject():
	m_position(0, 0)
{
	m_isActive = true;
}

void GameObject::AddComponent(PhysicsObject component)
{
	m_physics.push_back(component);
	Level* active = Level::GetActiveLevel();
	active->AddComponent(component);
}

void GameObject::AddComponent(Behaviour component)
{
	m_behaviours.push_back(component);
	Level* active = Level::GetActiveLevel();
	active->AddComponent(component);
}

void GameObject::AddComponent(Renderer component)
{
	m_renderers.push_back(component);
	Level* active = Level::GetActiveLevel();
	active->AddComponent(component);
}
