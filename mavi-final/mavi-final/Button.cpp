#include "Button.h"

Button::Button(sf::Vector2f position) :
	m_buttonBody({ 256, 16 })
{
	m_eTime = 0;
	m_sizeFactor = 0.1;
	m_animationSpeed = 4;
	m_isSelected = false;

	m_buttonBody.setFillColor(sf::Color::Yellow);
	sf::FloatRect bodyBounds = m_buttonBody.getLocalBounds();
	m_buttonBody.setOrigin({ bodyBounds.width / 2, bodyBounds.height / 2 });
	m_buttonBody.setPosition({ position.x, position.y + bodyBounds.height + 32});


	sf::Font* font = new sf::Font();
	font->loadFromFile("assets/font.ttf");
	m_buttonText.setFont(*font);
	m_buttonText.setCharacterSize(48);
	m_buttonText.setFillColor(sf::Color::White);
	m_buttonText.setString("PLAY");
	sf::FloatRect textBounds = m_buttonText.getLocalBounds();
	m_buttonText.setPosition({ position.x - (textBounds.width / 2), position.y - (textBounds.height / 2) });
}

void Button::Update(float dt)
{
	if (m_isSelected)
	{
		m_eTime += dt;
		float factor = 1 + (sin(m_eTime * m_animationSpeed) * m_sizeFactor);

		m_buttonBody.setScale(factor, 1);

		sf::Color c = m_buttonBody.getFillColor();
		c.a = static_cast<sf::Uint8>(1 + (-0.5) * factor);
		m_buttonBody.setFillColor(c);
	}
}

void Button::Draw(sf::RenderTexture& window)
{
	if (m_isSelected)
	{
		window.draw(m_buttonBody);
	}
	window.draw(m_buttonText);
}

void Button::Select() {
	m_isSelected = true;
	m_eTime = 0;
};
void Button::Deselect() {
	m_isSelected = false;
};
void Button::Submit() {};