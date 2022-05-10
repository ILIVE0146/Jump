#include"GameEngine.hpp"
#include "MainmenuState.hpp"
// #include<iostream>
namespace GameEngine{
    Game::Game(int width, int height, std::string title,std::string iconString){
        data->window.create(sf::VideoMode(width,height), title, sf::Style::Close | sf::Style::Titlebar);
        data->window.setFramerateLimit(60);
        data->machine.addState(stateRef(new MainmenuState(this->data)));
        sf::Image image;
        image.loadFromFile(iconString);
        data->window.setIcon(image.getSize().x,image.getSize().y,image.getPixelsPtr());
        this->Run();
    }
    void Game::Run(){
        float newTime, frameTime;
        float currentTime = this->clock.getElapsedTime().asSeconds();
        while(this->data->window.isOpen()){
            this->data->machine.processStateChanges();
            newTime = this->clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            // std::cout<<1/frameTime<<std::endl;
            currentTime = newTime;
            this->data->machine.getActiveState()->handleInput();
            this->data->machine.getActiveState()->update(frameTime);
            this->data->machine.getActiveState()->Draw(frameTime);   
        }
    }
}