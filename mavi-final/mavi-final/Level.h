#include "GameObject.h"
#include "Behaviour.h"
#include "PhysicsObject.h"
#include "Renderer.h"
#pragma once

class Level
{
private:
	static Level* m_activeLevel;
	std::vector<GameObject> m_gameObjects;
	std::vector<Behaviour> m_behaviours;
	std::vector<PhysicsObject> m_physicsObjects;
	std::vector<Renderer> m_renderers; //Maybe a list

public:
	Level();
	void AddGameObject(GameObject obj);
	void ProcessPhysics();
	void UpdateBehaviours(float dt);
	sf::Sprite DrawObjects();
	static Level* GetActiveLevel();


	void AddComponent(PhysicsObject component);
	void AddComponent(Behaviour component);
	void AddComponent(Renderer component);
};

