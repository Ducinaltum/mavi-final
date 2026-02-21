#pragma once
#include "GameObject.h"
#include "IDisposable.h"
class Explotion :
    public GameObject, IDisposable
{
private:
    float m_fps;
    float m_eTime = 0;
    int m_currentFrame = 0;
    int m_frameCount;
    sf::Vector2i m_rectSize;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    std::vector<sf::IntRect> m_frames;
public:
    Explotion(float fps, sf::Vector2i size = {250, 250});
    // Inherited via GameObject
    void Update(float dt) override;
    void OnCollision(GameObject* other) override;
    void Draw(sf::RenderTexture& rt) override;

    void Activate(sf::Vector2f position);
    void Dispose() override;

    void SetSize(float width);
};

