#include "EnemyRed.h"
#include "Globals.h"
#include "Extensions.h"


EnemyRed::EnemyRed(float targetWidth): GameObject(), m_velocity(), m_texture(), m_sprite()
{
	m_velocity.x = 100.0f;
	m_texture.loadFromFile("assets/gameplay/Enemigo1.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(targetWidth, m_texture);
	m_sprite.setScale(scale, scale);
	m_position.x = TARGET_WIDTH /2 ;
	m_position.y = (TARGET_HEIGHT / 2) - (m_sprite.getGlobalBounds().height / 2);
	m_isActive = true;
	m_colliders.push_back(m_sprite.getGlobalBounds());
}

void EnemyRed::Update(float dt)
{
	m_position -= m_velocity * dt;
}

sf::Sprite EnemyRed::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}
