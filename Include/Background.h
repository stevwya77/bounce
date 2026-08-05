#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Background
{
private:
    sf::Texture texture_;
    sf::Sprite sprite_;

public:
    Background();

    void Draw(sf::RenderWindow& window) const;
    
};