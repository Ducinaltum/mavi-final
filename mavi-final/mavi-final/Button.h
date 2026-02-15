#pragma once
#include "GameObject.h"

class Button
{
private:
	sf::RectangleShape m_buttonBody;
	sf::Text m_buttonText;
	sf::Color m_bodyColor;
	float m_eTime;
	float m_growFactor;
	float m_animationSpeed;
	sf::String m_action;
	bool m_isSelected;

public:
	Button(sf::Vector2f position, sf::String text);
	void Update(float dt);
	void Draw(sf::RenderTexture& window);

	void Select();
	void Deselect();
	void Submit();
};

