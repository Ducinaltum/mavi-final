#include "EndOfGame.h"
#include "Parallax.h"
#include "Globals.h"
#include "Label.h"

EndOfGame::EndOfGame(bool hasWon, int score)
{
	Parallax* paralax_0 = new Parallax(0);
	Parallax* paralax_1 = new Parallax(1);
	m_gameObjects.push_back(paralax_0);
	m_gameObjects.push_back(paralax_1);

	sf::String outcome = hasWon ? "WON" : "LOST";
	Label* outcomeLabel = new Label(sf::Vector2f((TARGET_WIDTH / 2), 256), "YOU HAVE " + outcome, 64, true);
	m_gameObjects.push_back(outcomeLabel);
	Label* scoreLabel = new Label(sf::Vector2f((TARGET_WIDTH / 2), 384), "Your score was: " + std::to_string(score), 32, true);
	m_gameObjects.push_back(scoreLabel);

	Button* continueButton = new Button(sf::Vector2f((TARGET_WIDTH / 2), TARGET_HEIGHT - 128), "CONTINUE");
	m_buttons.push_back(continueButton);
	m_gameObjects.push_back(continueButton);

	m_navigation.SetObjects(m_buttons);
}

//No me gusta dejar esto vacío pero no hay nada que procesar
void EndOfGame::ProcessCollisions(){}

void EndOfGame::Update(float dt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			current->Update(dt);
		}
	}
	m_navigation.Update();
}

void EndOfGame::Draw(sf::RenderTexture& rt)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			current->Draw(rt);
		}
	}
}
