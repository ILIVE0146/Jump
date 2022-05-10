#pragma once
#include "State.hpp"
#include "GameEngine.hpp"
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "PlayState.hpp"
#include "MainmenuState.hpp"

class EndState : public GameEngine::State{
    public:
    EndState(GameEngine::GameDataRef data, int score);
    void init();
    void handleInput();
    void update(float dt);
    void Draw(float dt);
    private:
    GameEngine::GameDataRef data;
    sf::Sprite background;
    sf::Text retryBtnTxt;
    sf::Text GameOverTxt;
    sf::Text MainmenuBtnText;
    sf::Text FinalScoreText;
    sf::Text theScoreText;
    int finalScore;
};