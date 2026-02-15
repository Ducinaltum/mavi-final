#include "Health.h"

Health::Health(float maxHealth)
{
	m_maxHealth = maxHealth;
	m_currentHealth = m_maxHealth;
}

void Health::RecieveDamage(float damage)
{
	m_currentHealth -= damage;
	if (m_currentHealth <= 0)
	{
		m_isDead = true;
	}
}

bool Health::IsDead()
{
	return m_isDead;
}

float Health::GetStatus()
{
	return m_currentHealth / m_maxHealth;
}
