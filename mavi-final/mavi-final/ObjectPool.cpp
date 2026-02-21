#include <queue>
#include "Bullet.h"
#include <iostream>

template <typename T>
class ObjectPool
{

private:
    ObjectPool() {}                 // Private constructor
    ~ObjectPool() {}                // Private destructor
    ObjectPool(const ObjectPool&) = delete; // Prevent copy
    void operator=(const ObjectPool&) = delete; // Prevent assignment
    std::queue<T*> m_bullets;

public:
    // Get the single instance
    static ObjectPool<T>& Instance()
    {
        static ObjectPool<T> instance; // Created only once 
        return instance;
    }

    T * GetElement()
    {
        if (m_bullets.empty())
        {
            std::cout << "We are short of bullets" << std::endl;
            return NULL;
        }
        T* b = m_bullets.front();
        m_bullets.pop();
        return b;
    }

    void Dispose(T * bullet)
    {
        bullet->Dispose();
        m_bullets.push(bullet);
    }

    void Clear()
    {
        while (!m_bullets.empty())
        {
            T* b = m_bullets.front();
            m_bullets.pop();
            delete b;
        }
    }
};