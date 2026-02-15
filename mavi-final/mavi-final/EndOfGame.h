#pragma once
#include "Scene.h"
#include "MenuNavigation.h"
class EndOfGame :
    public Scene
{
private:
	MenuNavigation m_navigation;
	std::vector<Button*> m_buttons;

public:
	EndOfGame(bool hasWon);
	void ProcessCollisions();
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

