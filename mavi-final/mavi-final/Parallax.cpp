#include "Parallax.h"
#include "Extensions.h"
#include "Globals.h"

Parallax::Parallax(int index):
	GameObject(), m_sprite()
{
	m_speed = 30;
	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/Background.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale((float)TARGET_WIDTH, *t);
	m_sprite.setScale(scale, scale);
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

void Parallax::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
}
