#include "MainMenuNavigation.h"

MainMenuNavigation::MainMenuNavigation()
{
	m_selectedObjectIndex = 0;
}

void MainMenuNavigation::SetObjects(std::vector<Button*> selectableObjects)
{
	m_selectableObjects = selectableObjects;
	m_selectableObjects[m_selectedObjectIndex]->Select();
}

void MainMenuNavigation::Update()
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

	if (Input::InputHandler::Confirm.GetButtonDown())
	{
		m_selectableObjects[m_selectedObjectIndex]->Submit();
	}
}

Button* MainMenuNavigation::GetSelectedButton()
{
	return m_selectableObjects[m_selectedObjectIndex];
}
