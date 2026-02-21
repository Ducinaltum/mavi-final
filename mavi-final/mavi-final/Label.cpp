#include "Label.h"

Label::Label(sf::Vector2f position, sf::String text, int size, bool isCentered)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("assets/font.ttf");
	m_labelText.setFont(*font);
	m_labelText.setCharacterSize(size);
	m_labelText.setFillColor(sf::Color::White);
	m_labelText.setString(text);
	sf::FloatRect textBounds = m_labelText.getLocalBounds();
	if(isCentered)
		m_labelText.setPosition({ position.x - (textBounds.width / 2), position.y - (textBounds.height / 2) });
	else
		m_labelText.setPosition(position);
}

//No me gusta dejarlo vacio, pero hereda de GameObject
void Label::Update(float dt) {}

void Label::Draw(sf::RenderTexture& window)
{
	window.draw(m_labelText);
}
