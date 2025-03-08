#include "PlayerShip.h"
#include "InputHandler.h"

PlayerShip::PlayerShip(): GameObject(), m_velocity(), m_texture(), m_sprite()
{
    m_speed = 1.0f;
    m_texture.loadFromFile("assets/ship.png");
    m_sprite.setTexture(m_texture);
}

void PlayerShip::Update(float dt)
{
    m_velocity = Input::InputHandler::Movement1;
    m_position += m_velocity;
}

sf::FloatRect PlayerShip::GetCollider()
{
    return sf::FloatRect();
}

sf::Sprite PlayerShip::Draw()
{
    return m_sprite;
}
