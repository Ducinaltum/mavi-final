#include "Wave.h"
#include "EnemyRed.h"
#include "EnemyPurple.h"
#include "EnemyBlue.h"
#include "EnemyGreen.h"
#include "EnemyOrange.h"

#include "Globals.h"

Wave::Wave(int waveIndex, GameObject* playerShip)
{
	m_boss = NULL;
	m_currentWaveIndex = waveIndex - 1;
	m_playerShip = playerShip;
	m_waves =
	{
		//Wave 0 => Red
		{
			{  EnemyType::Red, sf::Vector2f(0, (TARGET_HEIGHT / 2)) },
			{  EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3)) },
			{  EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3) * 2)},
			{  EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4))},
			{  EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 2)},
			{  EnemyType::Red, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3) },
		},
		//Wave 1 => Green
		{
			{ EnemyType::Green, sf::Vector2f(0, (TARGET_HEIGHT / 2)) },

			{ EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3)) },
			{ EnemyType::Red, sf::Vector2f(512, (TARGET_HEIGHT / 3) * 2) },

			{ EnemyType::Green, sf::Vector2f(1024, (TARGET_HEIGHT / 4)) },
			{ EnemyType::Red, sf::Vector2f(1024 + 256, (TARGET_HEIGHT / 4) * 2) },
			{ EnemyType::Green, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3) },
		},
		//Wave 2 => Orange
		{
			{ EnemyType::Red, sf::Vector2f(0, (TARGET_HEIGHT / 3)) },
			{ EnemyType::Red, sf::Vector2f(0, (TARGET_HEIGHT / 3) * 2) },
			{ EnemyType::Green, sf::Vector2f(256, (TARGET_HEIGHT / 2)) },

			{ EnemyType::Green, sf::Vector2f(512 + 256,  (TARGET_HEIGHT / 5)*2) },
			{ EnemyType::Orange, sf::Vector2f(1024, (TARGET_HEIGHT / 4)) },
			{ EnemyType::Orange, sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3) },
			{ EnemyType::Green, sf::Vector2f(512 + 256,  (TARGET_HEIGHT / 5)*3) },
		},
		//Wave 3 => Red, Green and Orange
		{
			{ EnemyType::Red, sf::Vector2f(0, (TARGET_HEIGHT / 3)) },
			{ EnemyType::Orange, sf::Vector2f(0, (TARGET_HEIGHT / 2)) },
			{ EnemyType::Red, sf::Vector2f(0, (TARGET_HEIGHT / 3) * 2) },

			{ EnemyType::Orange, sf::Vector2f(512, (TARGET_HEIGHT / 4)) },
			{ EnemyType::Green, sf::Vector2f(512 + 256, (TARGET_HEIGHT / 2)) },
			{ EnemyType::Orange, sf::Vector2f(512, (TARGET_HEIGHT / 4) * 3) },

			{ EnemyType::Green, sf::Vector2f(1024,  (TARGET_HEIGHT / 4)) },
			{ EnemyType::Orange, sf::Vector2f(1024 + 256, (TARGET_HEIGHT / 5) * 2) },
			{ EnemyType::Orange, sf::Vector2f(1024 + 256, (TARGET_HEIGHT / 5) * 3) },
			{ EnemyType::Green, sf::Vector2f(1024,  (TARGET_HEIGHT / 4) * 3) },
		},
		//Wave 4 => Blue
		{
			{ EnemyType::Blue, sf::Vector2f(0, (TARGET_HEIGHT / 3)) },

			{ EnemyType::Green, sf::Vector2f(512, (TARGET_HEIGHT / 4)) },
			{ EnemyType::Orange, sf::Vector2f(512 + 256, (TARGET_HEIGHT / 2)) },
			{ EnemyType::Green, sf::Vector2f(512, (TARGET_HEIGHT / 4) * 3) },

			{ EnemyType::Blue, sf::Vector2f(1024,  (TARGET_HEIGHT / 4)) },
			{ EnemyType::Green, sf::Vector2f(1024 + 256, (TARGET_HEIGHT / 5) * 2) },
			{ EnemyType::Green, sf::Vector2f(1024 + 256, (TARGET_HEIGHT / 5) * 3) },
			{ EnemyType::Blue, sf::Vector2f(1024,  (TARGET_HEIGHT / 4) * 3) },

			{ EnemyType::Orange, sf::Vector2f(1024, (TARGET_HEIGHT / 5) * 2) },
			{ EnemyType::Blue, sf::Vector2f(1024 + 256,  (TARGET_HEIGHT / 4)) },
			{ EnemyType::Blue, sf::Vector2f(1024 + 256,  (TARGET_HEIGHT / 4) * 3) },
			{ EnemyType::Orange, sf::Vector2f(1024, (TARGET_HEIGHT / 5) * 3) }
		},
		//Wave 5 => Boss
		{
			{ EnemyType::Purple, sf::Vector2f(0, (TARGET_HEIGHT / 2)) },
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
			case EnemyType::Orange:
				m_enemies.push_back(new EnemyOrange(spawn.Position, m_playerShip));
				break;
			case EnemyType::Blue:
				m_enemies.push_back(new EnemyBlue(spawn.Position, m_playerShip));
				break;			
			case EnemyType::Purple:
				EnemyPurple* e = new EnemyPurple(spawn.Position);
				m_boss = e;
				m_enemies.push_back(e);
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

Enemy* Wave::GetBoss()
{
	return m_boss;
}
