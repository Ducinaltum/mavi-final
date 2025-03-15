#pragma once
#include "GameObject.h"
#include "IDisposable.h"

class Bullet :
    public GameObject, IDisposable
{
private:
    float m_speed;
    sf::Vector2f m_velocity;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    Bullet(float targetWidth);
    // Inherited via GameObject
    void Update(float dt) override;
    sf::Sprite Draw() override;

    void Activate(sf::Vector2f position);
    void Dispose() override;

};

