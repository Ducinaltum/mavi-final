#include "Parallax.h"
#include "Extensions.h"
#include "Globals.h"

Parallax::Parallax(int index):
	GameObject(), m_texture(), m_sprite()
{
	m_speed = 30;
	m_texture.loadFromFile("assets/gameplay/Background.png");
	m_sprite.setTexture(m_texture);
	float scale = Extensions::GetTargetScale(TARGET_WIDTH, m_texture);
	m_sprite.setScale(scale, scale);
	//m_position.y = 0;
	m_position.x = TARGET_WIDTH * index;
}

void Parallax::Update(float dt)
{
	m_position.x -= m_speed * dt;
	if (m_position.x < (TARGET_WIDTH * -1))
	{
		m_position.x = TARGET_WIDTH;
	}
}

sf::Sprite Parallax::Draw()
{
	m_sprite.setPosition(m_position);
	return m_sprite;
}
