#pragma once
#include "Scene.h"
#include "MainMenu.h"
#include "GamePlay.h"

class GameManager
{
public:
    enum SceneType
    {
        NONE,
        MAIN_MENU,
        GAMEPLAY,
        WIN_GAME,
        LOOSE_GAME
    };

private:
    GameManager() = default;
    ~GameManager() = default;

    SceneType m_changeToScene;

    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

public:
    static GameManager& Instance()
    {
        static GameManager instance;
        return instance;
    }

    void ChangeScene(GameManager::SceneType nextScene)
    {
        m_changeToScene = nextScene;
    }

    Scene* GetNewScene()
    {
        if (m_changeToScene == GameManager::SceneType::NONE)
        {
            return NULL;
        }
        else
        {
            Scene* newScene = NULL; 
            switch (m_changeToScene)    
            {
            case GameManager::MAIN_MENU:
                newScene = new MainMenu();
                break;
            case GameManager::GAMEPLAY:
                newScene = new Gameplay();
                break;
            case GameManager::WIN_GAME:
                break;
            case GameManager::LOOSE_GAME:
                break;
            default:
                break;
            }
            m_changeToScene = GameManager::SceneType::NONE;
            return newScene;
        }
    }
};
