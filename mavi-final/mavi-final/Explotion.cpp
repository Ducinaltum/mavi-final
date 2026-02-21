#include "Explotion.h"
#include "ImagesController.cpp"
#include "Extensions.h"
#include "ObjectPool.cpp"

Explotion::Explotion(float fps, sf::Vector2i size):
	GameObject(), m_sprite()
{
	m_rectSize = size;
	m_fps = fps;
	m_eTime = 0;
	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/Explosion.png");
	m_sprite.setTexture(*t);
	m_position.x = 300;
	m_position.y = 200;
	for (int y = 0; y < 6; y++)
		for(int x = 0; x < 4; x++)
		{
			m_frames.push_back({ x * m_rectSize.x, y * m_rectSize.y, m_rectSize.x, m_rectSize.y });
		}
	m_frameCount = m_frames.size();
	ObjectPool<Explotion>::Instance().Dispose(this);
}

void Explotion::Update(float dt)
{
	m_eTime += dt;
	m_currentFrame = static_cast<int>(m_eTime * m_fps);
	if (m_currentFrame > m_frameCount - 1)
	{
		m_currentFrame = m_frameCount - 1;
		ObjectPool<Explotion>::Instance().Dispose(this);
	}
	else
	{
		m_sprite.setTextureRect(m_frames[m_currentFrame]);
	}
}

void Explotion::OnCollision(GameObject* other) {}

void Explotion::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
}

void Explotion::Activate(sf::Vector2f position)
{
	m_isActive = true;
	m_position = position;
}

void Explotion::Dispose()
{
	m_isActive = false;
}

void Explotion::SetSize(float width)
{
	float scale = Extensions::GetTargetScale(width, m_rectSize.x);
	m_sprite.setScale(scale, scale);
}
