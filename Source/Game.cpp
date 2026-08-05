#include "Game.h"
#include "Ball.h"
#include "algorithm"
#include "GameConfig.h"
#include "SFML/Graphics/Rect.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <optional>

Game::Game() :
    window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), "Bounce")
{
    window_.setFramerateLimit(60);
}

bool Game::IsRunning() const
{
    return window_.isOpen();
}

void Game::ProcessEvents()
{
    while (std::optional<sf::Event> event = window_.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window_.close();
        }
    }
}

void Game::Update()
{
    float deltaTime = clock_.restart().asSeconds();

    if (ballSpawnClock_.getElapsedTime().asSeconds() > gConfig.ballSpawnCooldown)
    {
        balls_.emplace_back();
        ballSpawnClock_.restart();
    }
    
    paddle_.Move(deltaTime);

    for (Ball& ball : balls_)
    {
        ball.Move(deltaTime);
    }

    HandleCollisions();

    if (stats_.GetLives() <= 0)
    {
        Restart();
    }
}

void Game::Render()
{
    window_.clear();
    background_.Draw(window_);
    paddle_.Draw(window_);
    
    for (const Ball& ball : balls_)
    {
        ball.Draw(window_);
    }
    stats_.Draw(window_);

    window_.display();
}

void Game::HandleCollisions()
{
    sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();
    
    for (Ball& ball : balls_)
    {
        sf::FloatRect ballBounds = ball.GetGlobalBounds();
        bool isColliding = ballBounds.findIntersection(paddleBounds).has_value();

        if (isColliding && ball.GetDirection().y > 0)
        {
            ball.Bounce();
            stats_.SetScore(stats_.GetScore() + 1);
            sounds_.PlayBounceSound();
        }
    }

    std::size_t ballsMissed = std::erase_if(balls_, [] (const Ball& ball) { return ball.IsOutside(); });
    if (ballsMissed > 0)
    {
        stats_.SetLives(stats_.GetLives() - ballsMissed);
    }
}

void Game::Restart()
{
    balls_.clear();
    ballSpawnClock_.restart();
    stats_.Reset();
}