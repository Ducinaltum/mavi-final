#include "ButtonState.h"
#include <iostream>
using namespace std;

//Registra los cambios de estado de un botón para obtener los tres estados básicos
//Apretado/suelto
//Apretado en este frame
//Suelto en este frame
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
