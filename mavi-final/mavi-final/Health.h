#pragma once
class Health
{
private:
	float m_currentHealth;
	float m_maxHealth;
	bool m_isDead;
public:
	Health(float maxHealth);
	void RecieveDamage(float damage);
	bool IsDead();
};

