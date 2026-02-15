#pragma once
#include "GameObject.h"
#include "InputHandler.h"
#include "Button.h"

class MenuNavigation
{
private:
	int m_selectedObjectIndex;
	std::vector<Button*> m_selectableObjects;
public:
	MenuNavigation();
	void SetObjects(std::vector<Button*> selectableObjects);
	void Update();
	Button* GetSelectedButton();
};


