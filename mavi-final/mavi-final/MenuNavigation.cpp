#include "MenuNavigation.h"

MenuNavigation::MenuNavigation()
{
	m_selectedObjectIndex = 0;
}

void MenuNavigation::SetObjects(std::vector<Button*> selectableObjects)
{
	m_selectableObjects = selectableObjects;
	m_selectableObjects[m_selectedObjectIndex]->Select();
}

void MenuNavigation::Update()
{
	int currentSelectedObject = m_selectedObjectIndex;
	if (Input::InputHandler::MenuDown.GetButtonDown())
	{
		m_selectedObjectIndex++;
		m_selectedObjectIndex %= m_selectableObjects.size();
	}
	if (Input::InputHandler::MenuUp.GetButtonDown())
	{
		m_selectedObjectIndex--;
		if (m_selectedObjectIndex < 0)
			m_selectedObjectIndex = m_selectableObjects.size() - 1;
	}
	if (currentSelectedObject != m_selectedObjectIndex)
	{
		m_selectableObjects[currentSelectedObject]->Deselect();
		m_selectableObjects[m_selectedObjectIndex]->Select();
	}

	if (Input::InputHandler::Confirm.GetButtonDown() || Input::InputHandler::Action1.GetButtonDown())
	{
		m_selectableObjects[m_selectedObjectIndex]->Submit();
	}
}

Button* MenuNavigation::GetSelectedButton()
{
	return m_selectableObjects[m_selectedObjectIndex];
}
