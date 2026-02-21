#include "Button.h"
#include "GameManager.cpp"

//El botón tiene un texto, y su "cuerpo" no es necesario ya que no es clickeable,
//lo que se decidió es colocar una barra que titila por debajo del texto indicando "Selección"
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
	//Origen al centro
	m_buttonBody.setOrigin({ bodyBounds.width / 2, bodyBounds.height / 2 });
	//Centramos en x pero no en y ya que este "body" debe estar ligeramente por debajo del texto 
	m_buttonBody.setPosition({ position.x, position.y + bodyBounds.height + 32 });


	sf::Font* font = new sf::Font();
	//Debería hace un manager para esta Font.
	//Igual, Dios saber que he cometido omisiones peores en mi vide
	font->loadFromFile("assets/font.ttf");
	m_buttonText.setFont(*font);
	m_buttonText.setCharacterSize(48);
	m_buttonText.setFillColor(sf::Color::White);
	m_buttonText.setString(m_action);
	sf::FloatRect textBounds = m_buttonText.getLocalBounds();
	//Acá no hace falta offset en y
	m_buttonText.setPosition({ position.x - (textBounds.width / 2), position.y - (textBounds.height / 2) });
}

void Button::Update(float dt)
{
	if (m_isSelected)
	{
		m_eTime += dt;
		float sineValue = (1 + (sin(m_eTime * m_animationSpeed))) * 0.5f; //remap sine from -1/1 to 0/1
		float xSize = 1 + (sineValue * m_growFactor);
		//Se hace agrandar y achicar la barra solo en el eje x
		m_buttonBody.setScale(xSize, 1);

		sf::Color c = m_bodyColor;
		c.a = static_cast<sf::Uint8>(sineValue * UCHAR_MAX); //UCHAR_MAX should be 255
		//Se hace titilar la barra modificando solo el alpha
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

//No me gusta poner esto acá, me gustaría usar eventos, pero se va fuera del scope de la materia
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