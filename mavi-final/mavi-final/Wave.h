#pragma once
#include "Enemy.h"
#include <vector>
#include "GameObject.h"
#include "PlayerShip.h"
#include "EnemyPurple.h"

enum class EnemyType
{
	Red,
	Green,
	Orange,
	Blue,
	Purple
};

struct EnemySpawn
{
	EnemyType Type;
	sf::Vector2f Position;
};

using WaveDefinition = std::vector<EnemySpawn>;

class Wave
{
private:
	std::vector<GameObject*> m_enemies;
	std::vector<EnemySpawn> m_waveDeifinition;
	std::vector<WaveDefinition> m_waves;
	int m_currentWaveIndex = -1;
	GameObject* m_playerShip;
	Enemy* m_boss;
public:
	Wave(int waveIndex, GameObject* playerShip);
	void SpawnNextWave();
	bool IsCompleted();
	std::vector<GameObject*> GetObjects();
	bool RemainsAnyWave();
	Enemy* GetBoss();
};



