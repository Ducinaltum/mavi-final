#include "MainMenu.h"
#include "Parallax.h"
#include "Bullet.h"
#include "Globals.h"
#include "Label.h"

MainMenu::MainMenu() :
	m_navigation()
{
	Parallax* paralax_0 = new Parallax(0);
	Parallax* paralax_1 = new Parallax(1);
	m_gameObjects.push_back(paralax_0);
	m_gameObjects.push_back(paralax_1);

	Button* playButton = new Button(sf::Vector2f((TARGET_WIDTH / 2), (TARGET_HEIGHT / 2) - 128), "PLAY");
	m_gameObjects.push_back(playButton);
	m_buttons.push_back(playButton);

	Button* quitButton = new Button(sf::Vector2f((TARGET_WIDTH / 2), (TARGET_HEIGHT / 2)), "QUIT");
	m_gameObjects.push_back(quitButton);
	m_buttons.push_back(quitButton);

	Label* moveLabel = new Label(sf::Vector2f(64, TARGET_HEIGHT - 64), "WASD: move", 24);
	m_gameObjects.push_back(moveLabel);
	Label* shootLabel = new Label(sf::Vector2f(64, TARGET_HEIGHT - 128), "SPACE: shoot/submit", 24);
	m_gameObjects.push_back(shootLabel);

	m_navigation.SetObjects(m_buttons);
}

//No me gusta dejar esto vacío pero no hay nada que procesar
void MainMenu::ProcessCollisions() {};

void MainMenu::Update(float dt)
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

void MainMenu::Draw(sf::RenderTexture& rt)
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
