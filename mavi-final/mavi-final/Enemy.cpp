#include "Enemy.h"


Enemy::Enemy(float startHealth) : m_health(startHealth)
{

}

float Enemy::GetHealthStatus()
{
    return m_health.GetStatus();
}
