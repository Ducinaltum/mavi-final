#include "GameObject.h"
#pragma once
class Scene
{
protected:
	std::vector<GameObject*> m_gameObjects;
public:
	virtual ~Scene() = default;
	virtual void ProcessCollisions() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderTexture& window) = 0;
};

