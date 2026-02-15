#pragma once
#include "Scene.h"
#include "MainMenu.h"
#include "GamePlay.h"

class GameManager
{
public:
    enum class SceneType
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
    bool m_quit = false;

    SceneType m_changeToScene = SceneType::MAIN_MENU;

    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

public:
    static GameManager& Instance()
    {
        static GameManager instance;
        return instance;
    }

    void ChangeScene(SceneType nextScene)
    {
        m_changeToScene = nextScene;
    }

    Scene* GetNewScene()
    {
        if (m_changeToScene == SceneType::NONE)
        {
            return NULL;
        }
        else
        {
            Scene* newScene = NULL; 
            switch (m_changeToScene)    
            {
            case SceneType::MAIN_MENU:
                newScene = new MainMenu();
                break;
            case SceneType::GAMEPLAY:
                newScene = new Gameplay();
                break;
            case SceneType::WIN_GAME:
                break;
            case SceneType::LOOSE_GAME:
                break;
            default:
                break;
            }
            m_changeToScene = SceneType::NONE;
            return newScene;
        }
    }

    void QuitGame() { m_quit = true; }
    bool HasQuited() { return m_quit; }
};
