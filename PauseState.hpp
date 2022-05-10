#pragma once
#include "State.hpp"
#include "GameEngine.hpp"
#include <SFML/Graphics.hpp>
#include"Definitions.hpp"
#include"PlayState.hpp"
#include "MainmenuState.hpp"

class PauseState : public GameEngine::State{
    public:
    PauseState(GameEngine::GameDataRef data);
    void init();
    void handleInput();
    void update(float dt);
    void Draw(float dt);
    private:
    GameEngine::GameDataRef data;
    sf::Sprite background;
    sf::Sprite pauseSprite;
    sf::Text resumeBtnTxt;
    sf::Text pauseTxt;
    sf::Text MainmenuBtnText;
};