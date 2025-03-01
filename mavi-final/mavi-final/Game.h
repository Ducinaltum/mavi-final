#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once
class Game
{
private:
	RenderWindow m_win;
	void ProcessEvent(Event& evt);
	void ProcessCollisions();
	void UpdateGame();
	void DrawGame();
public:
	Game(int alto, int ancho, std::string titulo);
	~Game(void);
	void Go();
};

