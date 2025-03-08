#include "Component.h"
#include <SFML/Graphics.hpp>
#pragma once
class Renderer : Component
{
private:
	int m_layer;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:
	Renderer(int layer, sf::Texture texture);
	sf::Sprite Draw();
	int GetLayer();
};

