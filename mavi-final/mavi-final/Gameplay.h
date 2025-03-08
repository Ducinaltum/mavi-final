#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "PlayerShip.h"

class Gameplay :
    public Scene
{
public:
	Gameplay();
	void ProcessCollisions();
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

