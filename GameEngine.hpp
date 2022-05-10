#pragma once
#include"StateMachine.hpp"
#include"AssetManager.hpp"
#include"InputManager.hpp"
#include<string>
#include<SFML/Graphics.hpp>
namespace GameEngine{
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };
    
    typedef std::shared_ptr<GameData> GameDataRef;

    class Game{
    public:
        Game(int width,int height, std::string title,std::string iconString);
    private:
        sf::Clock clock;
        GameDataRef data = std::make_shared<GameData>();
        void Run();
        sf::Uint8 icon;
    };
}