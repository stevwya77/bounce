#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Ball
{
private:
    static sf::Texture& GetTexture();
    sf::CircleShape shape_;
    sf::Vector2f direction_;
    float speed_;

public:
    Ball();

    void Draw(sf::RenderWindow& window) const;
    void Move(float deltaTime);
    void Bounce();

    sf::FloatRect GetGlobalBounds() const;
    sf::Vector2f GetDirection() const;
    bool IsOutside() const;
};