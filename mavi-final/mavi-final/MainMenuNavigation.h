#pragma once
#include "GameObject.h"
#include "InputHandler.h"
#include "Button.h"

class MainMenuNavigation
{
private:
	int m_selectedObjectIndex;
	std::vector<Button*> m_selectableObjects;
public:
	MainMenuNavigation();
	void SetObjects(std::vector<Button*> selectableObjects);
	void Update();
	Button* GetSelectedButton();
};


