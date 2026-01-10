#pragma once
#include "PlayerShip.h"
#include "Enemy.h"
#include "Wave.h"
class HUD
{
private:
	PlayerShip* m_playerShip;
	Wave* m_wave;
	sf::RectangleShape m_shipHealth;
	sf::RectangleShape m_shipHealthBorder;
	sf::RectangleShape m_shipCooldown;
	sf::RectangleShape m_shipCooldownBorder;
	sf::Text m_shipScore;
	sf::RectangleShape m_bossHealth;
	sf::RectangleShape m_bossHealthBorder;
public:
	HUD(PlayerShip* playerShip, Wave* wave);
	void Update(float dt);
	void Draw(sf::RenderTexture& window);
};

