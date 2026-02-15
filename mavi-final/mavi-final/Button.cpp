#include "Button.h"
#include "GameManager.cpp"

Button::Button(sf::Vector2f position, sf::String text) :
	m_buttonBody({ 224, 16 }),
	m_bodyColor(sf::Color::Yellow)
{
	m_action = text;
	m_eTime = 0;
	m_growFactor = .2;
	m_animationSpeed = 4;
	m_isSelected = false;

	m_buttonBody.setFillColor(m_bodyColor);
	sf::FloatRect bodyBounds = m_buttonBody.getLocalBounds();
	m_buttonBody.setOrigin({ bodyBounds.width / 2, bodyBounds.height / 2 });
	m_buttonBody.setPosition({ position.x, position.y + bodyBounds.height + 32 });


	sf::Font* font = new sf::Font();
	font->loadFromFile("assets/font.ttf");
	m_buttonText.setFont(*font);
	m_buttonText.setCharacterSize(48);
	m_buttonText.setFillColor(sf::Color::White);
	m_buttonText.setString(m_action);
	sf::FloatRect textBounds = m_buttonText.getLocalBounds();
	m_buttonText.setPosition({ position.x - (textBounds.width / 2), position.y - (textBounds.height / 2) });
}

void Button::Update(float dt)
{
	if (m_isSelected)
	{
		m_eTime += dt;
		float sineValue = (1 + (sin(m_eTime * m_animationSpeed))) * 0.5f; //remap sine from -1/1 to 0/1
		float xSize = 1 + (sineValue * m_growFactor);
		m_buttonBody.setScale(xSize, 1);
		sf::Color c = m_bodyColor;
		c.a = static_cast<sf::Uint8>(sineValue * UCHAR_MAX); //UCHAR_MAX should be 255
		m_buttonBody.setFillColor(c);
	}
}

void Button::Draw(sf::RenderTexture& rt)
{
	if (m_isSelected)
	{
		rt.draw(m_buttonBody);
	}
	rt.draw(m_buttonText);
}

void Button::Select() 
{
	m_isSelected = true;
	m_eTime = 0;
};

void Button::Deselect() 
{
	m_isSelected = false;
};

void Button::Submit()
{
	if (m_action == "QUIT")
	{
		GameManager::Instance().QuitGame();
	}
	else if (m_action == "PLAY")
	{
		GameManager::Instance().ChangeScene(GameManager::SceneType::GAMEPLAY);
	}
	else if (m_action == "CONTINUE")
	{
		GameManager::Instance().ChangeScene(GameManager::SceneType::MAIN_MENU);
	}
};