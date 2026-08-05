#include "Background.h"
#include <SFML/Graphics/RenderWindow.hpp>

Background::Background() :
    texture_("Content/Background.png"),
    sprite_(texture_)
{
}

void Background::Draw(sf::RenderWindow& window) const
{
    window.draw(sprite_);
}