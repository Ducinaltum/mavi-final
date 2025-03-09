#include <queue>
#include "Bullet.h"
#include <iostream>

class GameplayManager
{
public:
    // Get the single instance
    static GameplayManager& Instance()
    {
        static GameplayManager instance; // Created only once
        return instance;
    }

    Bullet * GetBullet()
    {
        if (m_bullets.empty())
        {
            std::cout << "We are short of bullets" << std::endl;
            return NULL;
        }
        Bullet* b = m_bullets.front();
        m_bullets.pop();
        return b;
    }

    void DisposeBullet(Bullet * bullet)
    {
        std::cout << m_bullets.size() << std::endl;
        bullet->Dispose();
        m_bullets.push(bullet);
    }


private:
    GameplayManager() {}                 // Private constructor
    ~GameplayManager() {}                // Private destructor
    GameplayManager(const GameplayManager&) = delete; // Prevent copy
    void operator=(const GameplayManager&) = delete; // Prevent assignment
    std::queue<Bullet *> m_bullets;
};