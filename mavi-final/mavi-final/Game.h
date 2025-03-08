#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Scene.h"
using namespace sf;
#pragma once
class Game
{
private:
	Clock deltaClock;
	RenderTexture m_renderTarget;
	RenderWindow m_window;
	Scene * m_activeScene;
	void ProcessEvent(Event& evt);
	void ProcessCollisions();
	void UpdateGame(float dt);
	void DrawGame();
public:
	Game(int alto, int ancho, std::string titulo);
	~Game(void);
	void Go();
};

