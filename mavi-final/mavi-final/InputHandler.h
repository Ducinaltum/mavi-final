#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ButtonState.h"
using namespace sf;
#pragma once
namespace Input
{

	class InputHandler
	{

	public:
		static Vector2f Movement1;
		static Vector2f Movement2;

		static ButtonState MenuUp;
		static ButtonState MenuDown;
		
		static ButtonState Action1;
		static ButtonState Action2;
		static ButtonState Action3;
		static ButtonState Cancel;
		static ButtonState Confirm;

		InputHandler();

		static void HandleEvents();
	};
}

