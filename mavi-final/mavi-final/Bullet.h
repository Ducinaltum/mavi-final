#pragma once
#include "GameObject.h"
#include "IDisposable.h"

class Bullet :
    public GameObject, IDisposable
{
private:
    float m_speed;
    float m_damage;
    sf::Vector2f m_velocity;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    Bullet(float targetWidth);
    // Inherited via GameObject
    void Update(float dt) override;
    void OnCollision(GameObject* other) override;
    sf::Sprite Draw() override;

    float GetDamage();

    void Activate(sf::Vector2f position);
    void Dispose() override;

};

