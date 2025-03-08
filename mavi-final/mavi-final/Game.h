#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Level.h"
#pragma once

class Game
{
private:
	RenderWindow m_win;
	Level * m_currentLevel;
	void ProcessEvent(Event& evt);
	void ProcessCollisions();
	void UpdateGame(float dt);
	void DrawGame();
public:
	Game(int alto, int ancho, std::string titulo);
	~Game(void);
	void Go();
};

