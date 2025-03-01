#include "ButtonState.h"
#include <iostream>
using namespace std;

namespace Input
{
	void ButtonState::SetState(bool newState)
	{
		m_wasPressed = m_isPressed;
		m_isPressed = newState;
	}

	bool ButtonState::GetButton()
	{
		return m_isPressed;
	}

	bool ButtonState::GetButtonDown()
	{
		return m_isPressed && !m_wasPressed;
	}

	bool ButtonState::GetButtonUp()
	{
		return !m_isPressed && m_wasPressed;
	}
}
