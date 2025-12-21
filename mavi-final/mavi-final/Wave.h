#pragma once
#include "Enemy.h"
#include <vector>
#include "GameObject.h"
#include "PlayerShip.h"

class Wave
{
private:
	bool m_isLastWave;
	std::vector<GameObject*> m_enemies;
public:
	Wave(int waveIndex, GameObject* playerShip);
	bool IsCompleted();
	bool IsLastWave();
	std::vector<GameObject*> GetObjects();
};

