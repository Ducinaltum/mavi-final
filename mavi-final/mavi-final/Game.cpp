#include "Game.h"
#include "Gameplay.h"
#include <iostream>
#include "InputHandler.h"
#include "Globals.h"

Game::Game(int alto, int ancho, std::string titulo) :
	m_renderTarget(),
	m_window(sf::VideoMode(alto, ancho), titulo) //This should be physical screen size
{
	m_renderTarget.create(alto, ancho);
	m_activeScene = new Gameplay();
	Go();
}

Game::~Game(void) = default;

void Game::Go()
{
	/////Objeto para recibir eventos/////
	Event evt;
	while (m_window.isOpen())
	{
		Time dt = deltaClock.restart();
		float deltaTime = dt.asSeconds();
		/////Procesar eventos/////
		while (m_window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
				m_window.close();
		}
		Input::InputHandler::HandleEvents();
		/////Procesar colisiones/////
		ProcessCollisions();
		/////Actualizar estados de objetos/////
		UpdateGame(deltaTime);
		m_renderTarget.clear(sf::Color::Black);
		DrawGame();
		m_renderTarget.display();

		sf::Sprite scaledSprite(m_renderTarget.getTexture());

		m_window.clear(Color(255, 0, 0, 255));
		m_window.draw(scaledSprite);
		m_window.display();
	}
}

void Game::ProcessEvent(Event& evt)
{

}

void Game::ProcessCollisions()
{
	m_activeScene->ProcessCollisions();
}

void Game::UpdateGame(float dt)
{
	m_activeScene->Update(dt);
}

void Game::DrawGame()
{
	//sf::CircleShape shape(20.f);
	//shape.setFillColor(sf::Color::Green);
	m_activeScene->Draw(m_renderTarget);
}



