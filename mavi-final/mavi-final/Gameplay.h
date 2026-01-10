#pragma once
#include <queue>
#include "Scene.h"
#include "GameObject.h"
#include "PlayerShip.h"
#include "Bullet.h"
#include "EnemyRed.h"
#include "EnemyOrange.h"
#include "EnemyGreen.h"
#include "Wave.h"
#include "HUD.h"

class Gameplay :
    public Scene
{
private:
	int m_waveIndex;
	Wave * m_wave;
	PlayerShip* m_playerShip;
	HUD* m_hud;

public:
	Gameplay();
	void ProcessCollisions();
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

