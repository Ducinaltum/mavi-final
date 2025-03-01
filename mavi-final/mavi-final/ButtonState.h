#pragma once
namespace Input
{
	class ButtonState
	{
	private:
		bool m_isPressed;
		bool m_wasPressed;
	public:
		ButtonState()
		{
			m_isPressed = m_wasPressed = false;
		}
		void SetState(bool state);
		bool GetButton();
		bool GetButtonDown();
		bool GetButtonUp();

	};
}