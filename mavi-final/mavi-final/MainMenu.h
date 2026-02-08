#pragma once
#include "Scene.h"
#include "MainMenuNavigation.h"
#include "Button.h"
class MainMenu :
    public Scene
{
private:
	MainMenuNavigation m_navigation;
	std::vector<Button*> m_buttons;

public:
	MainMenu();
	void ProcessCollisions();
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

