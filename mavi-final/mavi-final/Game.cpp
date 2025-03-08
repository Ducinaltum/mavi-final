#include "Game.h"
#include "InputHandler.h"
#include "FirstLevel.h"

Game::Game(int alto, int ancho, std::string titulo) :
	m_win(sf::VideoMode(alto, ancho), titulo)
{
	m_currentLevel = new FirstLevel();
	Go();
}

Game::~Game(void)
{
}

void Game::Go()
{
	/////Objeto para recibir eventos/////
	//Event evt;
	while (m_win.isOpen())
	{
		Input::InputHandler::HandleEvents();
		/////Procesar colisiones/////
		ProcessCollisions();
		/////Actualizar estados de objetos/////
		UpdateGame(0.1f);
		m_win.clear();
		DrawGame();
		m_win.display();
	}
}

void Game::ProcessEvent(Event& evt)
{
	Input::InputHandler::HandleEvents();
}

void Game::ProcessCollisions()
{
	m_currentLevel->ProcessPhysics();
}

void Game::UpdateGame(float dt)
{
	m_currentLevel->UpdateBehaviours(dt);
}

void Game::DrawGame()
{
	//m_currentLevel->DrawObjects();
	sf::CircleShape shape(20.f);
	shape.setFillColor(sf::Color::Green);
	m_win.draw(shape);
}



