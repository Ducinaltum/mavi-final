#include "MainMenu.h"
#include "Parallax.h"
#include "Bullet.h"
#include "Globals.h"

MainMenu::MainMenu() :
	m_navigation()
{
	Parallax* paralax_0 = new Parallax(0);
	Parallax* paralax_1 = new Parallax(1);
	m_gameObjects.push_back(paralax_0);
	m_gameObjects.push_back(paralax_1);
	GameObject* bullet = new Bullet(25);
	m_gameObjects.push_back(bullet);
	Button* playButton = new Button(sf::Vector2f((TARGET_WIDTH / 2), 128));
	m_buttons.push_back(playButton);
	Button* quitButton = new Button(sf::Vector2f((TARGET_WIDTH / 2), 256));
	m_buttons.push_back(quitButton);
	m_navigation.SetObjects(m_buttons);
}

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
	for (int i = 0; i < m_buttons.size(); i++)
	{
		Button* current = m_buttons[i];
		current->Update(dt);
	}
	m_navigation.Update();
}

void MainMenu::Draw(sf::RenderTexture& window)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		if (current->GetIsActive())
		{
			window.draw(current->Draw());
		}
	}
	for (int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i]->Draw(window);
	}
}
