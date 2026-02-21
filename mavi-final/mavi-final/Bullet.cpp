#include "ObjectPool.cpp"
#include "Bullet.h"
#include "Extensions.h"
#include "Globals.h"
#include "ImagesController.cpp"
#include "Explotion.h"

//Bullet implementa IDispoable para poder enviarse y requerirse de una pool
Bullet::Bullet(float targetWidth) : GameObject(), m_velocity(), m_sprite()
{
	m_speed = 0.2f;
	m_damage = 10;
	sf::Texture* t = ImagesController::Instance().GetImage("assets/gameplay/bullet.png");
	m_sprite.setTexture(*t);
	float scale = Extensions::GetTargetScale(targetWidth, *t);
	m_sprite.setScale(scale, scale);
	m_velocity.x = m_speed;
	m_colliders.push_back(m_sprite.getGlobalBounds());
	ObjectPool<Bullet>::Instance().Dispose(this);
}

//En su update, esta entidad se mueve de manera lineal desde un lado de la pantalla al otro
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
	Explotion* e = ObjectPool<Explotion>::Instance().GetElement();
	if (e != nullptr)
	{
		sf::Vector2f offset(m_sprite.getGlobalBounds().width - m_sprite.getGlobalBounds().height, 0);
		e->Activate(m_position + offset);
		e->SetSize(m_sprite.getGlobalBounds().height * 4);
	}
	ObjectPool<Bullet>::Instance().Dispose(this);
}

void Bullet::Draw(sf::RenderTexture& rt)
{
	m_sprite.setPosition(m_position);
	rt.draw(m_sprite);
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
