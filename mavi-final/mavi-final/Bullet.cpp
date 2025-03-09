#include "GameplayManager.cpp"
#include "Bullet.h"
#include "Extensions.h"
#include "Globals.h"

Bullet::Bullet(float targetWidth): GameObject(), m_velocity(), m_texture(), m_sprite()
{
	m_speed = 0.2f;
	m_texture.loadFromFile("assets/gameplay/bullet.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_velocity.x = m_speed;
	GameplayManager::Instance().DisposeBullet(this);
}

void Bullet::Update(float dt)
{
	m_position += m_velocity;
	if (m_position.x > TARGET_WIDTH)
	{
		GameplayManager::Instance().DisposeBullet(this);
	}
}

sf::FloatRect Bullet::GetCollider()
{
	return sf::FloatRect();
}

sf::Sprite Bullet::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}

void Bullet::Activate(sf::Vector2f position)
{
	std::cout << "Activate bullet " << this << " at " << 
		position.x << " " << position.y << std::endl;
	m_isActive = true;
	m_position = position;
}

void Bullet::Dispose()
{
	m_isActive = false;
	std::cout << "Dispose bullet" << this <<std::endl;
}
