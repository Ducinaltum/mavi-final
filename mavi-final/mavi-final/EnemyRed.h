#pragma once
#include "GameObject.h"


class EnemyRed :
    public GameObject
{
private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_realSize;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	EnemyRed(float targetWidth);
	void Update(float dt) override;
	sf::Sprite Draw() override;
};

