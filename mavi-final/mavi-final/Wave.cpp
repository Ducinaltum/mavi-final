#include "Wave.h"
#include "EnemyRed.h"
#include "EnemyPurple.h"
#include "EnemyBlue.h"
#include "EnemyGreen.h"
#include "EnemyOrange.h"

#include "Globals.h"

Wave::Wave(int waveIndex, GameObject* playerShip)
{
	EnemyOrange* enemyOrange = new EnemyOrange(128, 10.0f, playerShip);
	EnemyGreen* enemyGreen = new EnemyGreen(128, 10.0f);
	EnemyBlue* enemyBlue = new EnemyBlue(128, 10.0f);
	EnemyPurple* enemyPurple = new EnemyPurple(128, 10.0f);
	switch (waveIndex)
	{
		case 0:
			//FIRST WAVE
			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(0, (TARGET_HEIGHT / 2)));
				m_enemies.push_back(enemy);
			}

			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(512, (TARGET_HEIGHT / 3)));
				m_enemies.push_back(enemy);
			}
			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(512, (TARGET_HEIGHT / 3) * 2));
				m_enemies.push_back(enemy);
			}

			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(1024, (TARGET_HEIGHT / 4)));
				m_enemies.push_back(enemy);
			}
			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 2));
				m_enemies.push_back(enemy);
			}
			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3));
				m_enemies.push_back(enemy);
			}
			break;
		case 1:
			//SECOND WAVE
			{
				EnemyGreen* enemy = new EnemyGreen(sf::Vector2f(0, (TARGET_HEIGHT / 2)));
				m_enemies.push_back(enemy);
			}

			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(512, (TARGET_HEIGHT / 3)));
				m_enemies.push_back(enemy);
			}
			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(512, (TARGET_HEIGHT / 3) * 2));
				m_enemies.push_back(enemy);
			}

			{
				EnemyGreen* enemy = new EnemyGreen(sf::Vector2f(1024, (TARGET_HEIGHT / 4)));
				m_enemies.push_back(enemy);
			}
			{
				EnemyRed* enemy = new EnemyRed(sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 2));
				m_enemies.push_back(enemy);
			}
			{
				EnemyGreen* enemy = new EnemyGreen(sf::Vector2f(1024, (TARGET_HEIGHT / 4) * 3));
				m_enemies.push_back(enemy);
			}
		break;

			break;
	default:
		break;
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
