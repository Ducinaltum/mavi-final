#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>

class ImagesController {
private:
	ImagesController() = default;
	~ImagesController() = default;

	ImagesController(const ImagesController&) = delete;
	ImagesController& operator=(const ImagesController&) = delete;

	std::map< std::string, sf::Texture > images_;

	void LoadImage(const std::string& filename)
	{
		images_[filename].loadFromFile(filename);
	}

public:
public:
	static ImagesController& Instance()
	{
		static ImagesController instance;
		return instance;
	}
	void Initialize()
	{
		LoadImage("assets/gameplay/Enemigo1.png");
		LoadImage("assets/gameplay/Enemigo2.png");
		LoadImage("assets/gameplay/Enemigo3.png");
		LoadImage("assets/gameplay/Enemigo4.png");
		LoadImage("assets/gameplay/Enemigo5.png");
		LoadImage("assets/gameplay/Background.png");
		LoadImage("assets/gameplay/bullet.png");
		LoadImage("assets/gameplay/ship.png");
		LoadImage("assets/gameplay/Explosion.png");
	}

	sf::Texture* GetImage(std::string id)
	{
		auto it = images_.find(id);
		if (it == images_.end())
			return nullptr;

		return &it->second;
	}
};
