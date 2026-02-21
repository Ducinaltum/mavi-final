#include "GameObject.h"

//Clase base de gran parte del juego
GameObject::GameObject(): m_position(), m_scale(1,1)
{
	m_isActive = true;
}