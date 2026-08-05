#pragma once

#include "SFML/Audio/Sound.hpp"
#include <SFML/Audio.hpp>

class GameSounds
{
private:
    sf::Music music_;
    
    sf::SoundBuffer bounceSoundBuffer_;
    sf::Sound bounceSound_;

public:
    GameSounds();

    void PlayBounceSound();
};