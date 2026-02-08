#pragma once
#include "GameObject.h"

class Button
{
private:
	sf::RectangleShape m_buttonBody;
	sf::Text m_buttonText;
	float m_eTime;
	float m_sizeFactor;
	float m_animationSpeed;
	bool m_isSelected;

public:
	Button(sf::Vector2f position);
	void Update(float dt);
	void Draw(sf::RenderTexture& window);

	void Select();
	void Deselect();
	void Submit();
};

