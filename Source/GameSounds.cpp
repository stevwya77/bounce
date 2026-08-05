#include "GameSounds.h"
#include "GameConfig.h"

GameSounds::GameSounds() :
    music_("Content/Music.wav"),
    bounceSoundBuffer_("Content/Bounce.wav"),
    bounceSound_(bounceSoundBuffer_)
{
    music_.setVolume(gConfig.musicVolume);
    music_.setLooping(true);
    music_.play();

    bounceSound_.setVolume(gConfig.bounceSoundVolume);
}

void GameSounds::PlayBounceSound()
{
    bounceSound_.play();
}