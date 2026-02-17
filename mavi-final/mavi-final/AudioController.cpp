#include <SFML/Audio.hpp>
#pragma once

class AudioController
{
public:
	enum class SFX
	{
		COLLISION,
		SHOT,
		EXPLOTION,
		RELOAD
	};

private:
	AudioController() = default;
	~AudioController() = default;
	sf::SoundBuffer m_collision;
	sf::SoundBuffer m_shot;
	sf::SoundBuffer m_explotion;
	sf::SoundBuffer m_reload;
	sf::Sound m_collisionPlayer;
	sf::Sound m_shotPlayer;
	sf::Sound m_explotionPlayer;
	sf::Sound m_reloadPlayer;
	sf::Music m_music;

	AudioController(const AudioController&) = delete;
	AudioController& operator=(const AudioController&) = delete;


	bool LoadSounds()
	{
		if (!m_collision.loadFromFile("assets/audio/colisionSound.wav")
			|| !m_shot.loadFromFile("assets/audio/shootSound.wav")
			|| !m_explotion.loadFromFile("assets/audio/explotionSound.wav")
			|| !m_reload.loadFromFile("assets/audio/reloadSound.wav")
			|| !m_music.openFromFile("assets/audio/backgroundMusic.ogg"));
		{
			return false;
		}

		m_shotPlayer.setBuffer(m_shot);
		m_explotionPlayer.setBuffer(m_explotion);
		m_collisionPlayer.setBuffer(m_collision);
		m_reloadPlayer.setBuffer(m_reload);
		m_music.setLoop(true);
		return true;
	}

public:
	static AudioController& Instance()
	{
		static AudioController instance;
		return instance;
	}

	void Initialize()
	{
		if (LoadSounds())
		{
			m_music.play();
		}
	}

	void PlaySFX(SFX sfx)
	{
		switch (sfx)
		{
		case AudioController::SFX::COLLISION:
			m_collisionPlayer.play();
			break;
		case AudioController::SFX::SHOT:
			m_shotPlayer.play();
			break;
		case AudioController::SFX::EXPLOTION:
			m_explotionPlayer.play();
			break;
		case AudioController::SFX::RELOAD:
			m_reloadPlayer.play();
			break;
		default:
			break;
		}
	}
};
