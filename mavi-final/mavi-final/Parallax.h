#pragma once
#include "GameObject.h"

class Parallax :
    public GameObject
{
private:
    float m_speed;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    Parallax(int index);
    void Update(float dt) override;
    sf::Sprite Draw() override;
};

