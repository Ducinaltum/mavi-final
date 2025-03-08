#include "Game.h"
#include "Gameplay.h"
#include <iostream>
#include "InputHandler.h"

Game::Game(int alto, int ancho, std::string titulo) :
	m_win(sf::VideoMode(alto, ancho), titulo)
{
	m_activeScene = new Gameplay();
	Go();
}

Game::~Game(void)
{
}

void Game::Go()
{
	/////Objeto para recibir eventos/////
	Event evt;
	while (m_win.isOpen())
	{
		/////Procesar eventos/////
		while (m_win.pollEvent(evt))
		{
			ProcessEvent(evt);
		}
		Input::InputHandler::HandleEvents();
		/////Procesar colisiones/////
		ProcessCollisions();
		/////Actualizar estados de objetos/////
		UpdateGame();
		m_win.clear();
		DrawGame();
		m_win.display();
	}
}

void Game::ProcessEvent(Event& evt)
{
	//Input::InputHandler::HandleEvents();
}

void Game::ProcessCollisions()
{
}

void Game::UpdateGame()
{
}

void Game::DrawGame()
{
	//sf::CircleShape shape(20.f);
	//shape.setFillColor(sf::Color::Green);
	m_activeScene->Draw(m_win);
}



