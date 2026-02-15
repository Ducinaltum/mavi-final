#include "HUD.h"
#include "Globals.h"

HUD::HUD(PlayerShip * playerShip, Wave* wave) :
	m_shipHealth({ 256, 24 }),
	m_shipHealthBorder({ 256, 24 }),
	m_shipCooldown({ 192, 16 }),
	m_shipCooldownBorder({ 192, 16 }),
	m_shipScore(),
	m_bossHealth({ 256, 24 }),
	m_bossHealthBorder({ 256, 24 })
{
	m_playerShip = playerShip;
	m_wave = wave;
	
	m_shipHealth.setFillColor(sf::Color::Red);
	m_shipHealth.setPosition((TARGET_WIDTH / 2) - 128, TARGET_HEIGHT - 104);
	m_shipHealthBorder.setFillColor(sf::Color::Blue);
	m_shipHealthBorder.setOutlineColor(sf::Color::White);
	m_shipHealthBorder.setOutlineThickness(2);
	m_shipHealthBorder.setPosition((TARGET_WIDTH / 2) - 128, TARGET_HEIGHT - 104);

	m_shipCooldown.setFillColor(sf::Color::Yellow);
	m_shipCooldown.setPosition((TARGET_WIDTH / 2) - 96, TARGET_HEIGHT - 64);
	m_shipCooldownBorder.setFillColor(sf::Color::Blue);
	m_shipCooldownBorder.setOutlineColor(sf::Color::White);
	m_shipCooldownBorder.setOutlineThickness(2);
	m_shipCooldownBorder.setPosition((TARGET_WIDTH / 2) - 96, TARGET_HEIGHT - 64);

	m_bossHealth.setFillColor(sf::Color::Red);
	m_bossHealth.setPosition(TARGET_WIDTH - 256 - 24, 24);
	m_bossHealthBorder.setFillColor(sf::Color::Blue);
	m_bossHealthBorder.setOutlineColor(sf::Color::White);
	m_bossHealthBorder.setOutlineThickness(2);
	m_bossHealthBorder.setPosition(TARGET_WIDTH - 256 - 24, 24);
	sf::Font* font = new sf::Font();
	font->loadFromFile("assets/font.ttf");
	m_shipScore.setFont(*font);
	m_shipScore.setCharacterSize(24);
	m_shipScore.setPosition(24, 24);
	m_shipScore.setFillColor(sf::Color::White);
	m_shipScore.setString("0");
}

void HUD::Update(float dt)
{
	m_shipHealth.setScale(m_playerShip->GetHealth()->GetStatus(), 1);
	m_shipCooldown.setScale(m_playerShip->GetCooldownStatus(), 1);
	m_shipScore.setString(std::to_string(m_playerShip->GetScore()));
	Enemy* boss = m_wave->GetBoss();
	if (boss != NULL)
	{
		m_bossHealth.setScale(boss->GetHealthStatus(), 1);
	}
}

void HUD::Draw(sf::RenderTexture& window)
{
	window.draw(m_shipHealthBorder);
	window.draw(m_shipHealth);
	window.draw(m_shipCooldownBorder);
	window.draw(m_shipCooldown);
	window.draw(m_shipScore);
	Enemy* boss = m_wave->GetBoss();
	if (boss != NULL)
	{
		window.draw(m_bossHealthBorder);
		window.draw(m_bossHealth);
	}
}
