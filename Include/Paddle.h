#pragma once

#include <SFML/Graphics.hpp>

class Paddle
{
private:
    static sf::Texture& GetTexture();
    sf::RectangleShape shape_;
    float speed_;

public:
    Paddle();

    void Draw(sf::RenderWindow& window) const;
    void Move(float deltaTime);

    sf::FloatRect GetGlobalBounds() const;
};