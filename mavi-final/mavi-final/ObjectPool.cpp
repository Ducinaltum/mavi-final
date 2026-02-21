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
    std::queue<T*> m_entities;

public:
    // Get the single instance
    static ObjectPool<T>& Instance()
    {
        static ObjectPool<T> instance; // Created only once 
        return instance;
    }

    T * GetElement()
    {
        if (m_entities.empty())
        {
            std::cout << "We are short of bullets" << std::endl;
            return NULL;
        }
        T* b = m_entities.front();
        m_entities.pop();
        return b;
    }

    void Dispose(T * entity)
    {
        entity->Dispose();
        m_entities.push(entity);
    }

    void Clear()
    {
        while (!m_entities.empty())
        {
            T* b = m_entities.front();
            m_entities.pop();
            delete b;
        }
    }
};