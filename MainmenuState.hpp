#pragma once
#include "State.hpp"
#include "GameEngine.hpp"
#include <SFML/Graphics.hpp>
#include"Definitions.hpp"
#include"PlayState.hpp"

class MainmenuState : public GameEngine::State{
    public:
    MainmenuState(GameEngine::GameDataRef data);
    void init();
    void handleInput();
    void update(float dt);
    void Draw(float dt);
    private:
    GameEngine::GameDataRef data;
    sf::Text playBtnText;
    sf::Text optionsBtnText;
    sf::Text exitBtnText;
    sf::Sprite background;
    sf::Text title;
};
