#pragma once
#include "GameObject.h"
class Label :
    public GameObject
{
private:
	sf::Text m_labelText;

public:
	Label(sf::Vector2f position, sf::String text, int size, bool isCentered = false);
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

