#include "ObjectPool.cpp"
#include "Bullet.h"
#include "Extensions.h"
#include "Globals.h"

Bullet::Bullet(float targetWidth): GameObject(), m_velocity(), m_texture(), m_sprite()
{
	m_speed = 0.2f;
	m_damage = 10;
	m_texture.loadFromFile("assets/gameplay/bullet.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_velocity.x = m_speed;
	m_colliders.push_back(m_sprite.getGlobalBounds());
	ObjectPool<Bullet>::Instance().Dispose(this);
}

void Bullet::Update(float dt)
{
	m_position += m_velocity;
	if (m_position.x > TARGET_WIDTH)
	{
		ObjectPool<Bullet>::Instance().Dispose(this);
	}
}

void Bullet::OnCollision(GameObject* other)
{
	ObjectPool<Bullet>::Instance().Dispose(this);
}

sf::Sprite Bullet::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}

float Bullet::GetDamage()
{
	return m_damage;
}

void Bullet::Activate(sf::Vector2f position)
{
	m_isActive = true;
	m_position = position;
}

void Bullet::Dispose()
{
	m_isActive = false;
}
