#include "Wave.h"
#include "EnemyRed.h"
#include "EnemyPurple.h"
#include "EnemyBlue.h"
#include "EnemyGreen.h"
#include "EnemyOrange.h"

#include "Globals.h"

Wave::Wave(int waveIndex, GameObject* playerShip)
{
	//EnemyOrange* enemyOrange = new EnemyOrange(128, 10.0f, playerShip);
	//EnemyBlue* enemyBlue = new EnemyBlue(128, 10.0f);
	//EnemyPurple* enemyPurple = new EnemyPurple(128, 10.0f);

	m_waves =
	{
		{
			{  EnemyType::Red, sf::Vector2f(0, (TARGET_HEIGHT / 2)) },
			{  EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3)) },
			{  EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3) * 2)},
			{  EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4))},
			{  EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 2)},
			{  EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3) },
		},
		{
			{ EnemyType::Green, sf::Vector2f(0, (TARGET_HEIGHT / 2)) },
			{ EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3)) },
			{ EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3) * 2) },
			{ EnemyType::Green, sf::Vector2f(1024, (TARGET_HEIGHT / 4)) },
			{ EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 2) },
			{ EnemyType::Green, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3) },
		}
	};
}

void Wave::SpawnNextWave()
{
	m_enemies.clear();
	m_currentWaveIndex++;
	if (m_currentWaveIndex < m_waves.size())
	{
		std::vector<EnemySpawn> wave = m_waves[m_currentWaveIndex];
		for (size_t i = 0; i < wave.size(); i++)
		{
			EnemySpawn spawn = wave[i];
			switch (spawn.Type)
			{
			case EnemyType::Red:
				m_enemies.push_back(new EnemyRed(spawn.Position));
				break;
			case EnemyType::Green:
				m_enemies.push_back(new EnemyGreen(spawn.Position));
				break;
			}
		}
	}
}

bool Wave::IsCompleted()
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		if (m_enemies[i]->GetIsActive()) {
			return false;
		}
	}
	return true;
}

std::vector<GameObject*> Wave::GetObjects()
{
	return m_enemies;
}

bool Wave::RemainsAnyWave()
{
	return m_currentWaveIndex < m_waves.size();;
}