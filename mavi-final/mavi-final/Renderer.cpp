#include "Renderer.h"
#include "Level.cpp"

Renderer::Renderer(int layer, sf::Texture texture)
{
    m_layer = layer;
	m_texture = texture;
    m_sprite.setTexture(m_texture);
}

sf::Sprite Renderer::Draw()
{
    return m_sprite;
}

int Renderer::GetLayer()
{
    return m_layer;
}
