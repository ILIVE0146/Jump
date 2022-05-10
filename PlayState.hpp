#pragma once
#include "State.hpp"
#include "GameEngine.hpp"
#include"Definitions.hpp"
#include <SFML/Graphics.hpp>
#include "PauseState.hpp"
#include <ctime>
#include "EndState.hpp"
struct Point{
    int x;
    int y;
};

class PlayState : public GameEngine::State{
    public:
    PlayState(GameEngine::GameDataRef data);
    void init();
    void handleInput();
    void update(float dt);
    void Draw(float dt);
    private:
    GameEngine::GameDataRef data;
    sf::Sprite background;
    sf::Sprite ball;
    sf::Sprite ledge[5];
    Point platform[5];
    float x,y,h;
    float dx, dy;
    float speed;
    int score;
    sf::RectangleShape rectForScore;
    sf::Text scoreText;
};