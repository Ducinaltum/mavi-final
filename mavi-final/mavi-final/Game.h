#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Scene.h"
using namespace sf;
#pragma once
class Game
{
private:
	RenderWindow m_win;
	Scene * m_activeScene;
	void ProcessEvent(Event& evt);
	void ProcessCollisions();
	void UpdateGame();
	void DrawGame();
public:
	Game(int alto, int ancho, std::string titulo);
	~Game(void);
	void Go();
};

