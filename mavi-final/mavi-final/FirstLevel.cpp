#include "FirstLevel.h"

FirstLevel::FirstLevel()
{
		GameObject player;
		Texture playerTexture;
		if (playerTexture.loadFromFile("assets/Nave.png"))
		{

		}
		player.AddComponent(*(new PhysicsObject()));
		player.AddComponent(*(new Behaviour()));
		player.AddComponent(*(new Renderer(2, playerTexture)));
		AddGameObject(player);
}
