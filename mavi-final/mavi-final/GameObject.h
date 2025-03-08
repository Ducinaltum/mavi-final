#include "InputHandler.h"
#include "Component.h"
#include "PhysicsObject.h"
#include "Behaviour.h"
#include "Renderer.h"

#pragma once
class GameObject
{
private:
	bool m_isActive;
	Vector2f m_position;
	std::vector<Component> m_components;
	std::vector<PhysicsObject> m_physics;
	std::vector<Behaviour> m_behaviours;
	std::vector<Renderer> m_renderers;

public:
	GameObject();

	void AddComponent(PhysicsObject component);
	void AddComponent(Behaviour component);
	void AddComponent(Renderer component);
	
};

