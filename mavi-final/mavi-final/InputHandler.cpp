#include "InputHandler.h"
namespace Input
{
	Vector2f InputHandler::Movement1;
	Vector2f InputHandler::Movement2;

	ButtonState InputHandler::Action1;
	ButtonState InputHandler::Action2;
	ButtonState InputHandler::Action3;
	ButtonState InputHandler::Cancel;
	ButtonState InputHandler::Confirm;

	InputHandler::InputHandler(){}

	void InputHandler::HandleEvents()
	{
		float movX = 0;
		float movY = 0;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			movY -= 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			movY += 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			movX -= 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			movX += 1;
		}
		InputHandler::Movement1.x = movX;
		InputHandler::Movement1.y = movY;
		Action1.SetState(Keyboard::isKeyPressed(Keyboard::Space));
		Action2.SetState(Keyboard::isKeyPressed(Keyboard::Q));
		Action3.SetState(Keyboard::isKeyPressed(Keyboard::R));
		Cancel.SetState(Keyboard::isKeyPressed(Keyboard::Escape));
		Confirm.SetState(Keyboard::isKeyPressed(Keyboard::Enter));
	}
}