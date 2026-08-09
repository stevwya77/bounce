#include "Paddle.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include "GameConfig.h"

sf::Texture& Paddle::GetTexture()
{
    static sf::Texture texture("Content/paddle.png");
    return texture;
}

Paddle::Paddle() :
    shape_(gConfig.paddleSize),
    speed_(gConfig.paddleSpeed)
{
    shape_.setTexture(&GetTexture());
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({gConfig.windowSize.x * 0.50f, gConfig.windowSize.y * 0.85f});
}

void Paddle::Draw(sf::RenderWindow& window) const
{
    window.draw(shape_);
}

void Paddle::Move(float deltaTime)
{
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        shape_.move({speed_ * deltaTime, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        shape_.move({-speed_ * deltaTime, 0});
    }

    float halfWidth = shape_.getSize().x / 2;
    float x = std::clamp(shape_.getPosition().x, halfWidth, gConfig.windowSize.x - halfWidth);
    shape_.setPosition({x, shape_.getPosition().y});
}

sf::FloatRect Paddle::GetGlobalBounds() const
{
    return shape_.getGlobalBounds();
}
