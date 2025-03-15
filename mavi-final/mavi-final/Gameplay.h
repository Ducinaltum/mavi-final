#pragma once
#include <queue>
#include "Scene.h"
#include "GameObject.h"
#include "PlayerShip.h"
#include "Bullet.h"
#include "EnemyRed.h"

class Gameplay :
    public Scene
{
private:

public:
	Gameplay();
	void ProcessCollisions();
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

