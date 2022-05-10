#include"MainmenuState.hpp"

MainmenuState::MainmenuState(GameEngine::GameDataRef data):data(data){}
void MainmenuState::init(){
    this->data->assets.LoadFont("Text Font", TEXTFONT);
    this->data->assets.LoadTexture("Background image", BACKGROUNDPNG);
    this->data->assets.LoadTexture("ball image", BALLPNG);
    this->data->assets.LoadTexture("Ledge image", LEDGEPNG);

    this->background.setTexture(this->data->assets.getTexture("Background image"));

    this->title.setFont(this->data->assets.getFont("Text Font"));
    this->title.setString("JUMP");
    this->title.setCharacterSize(128);
    this->title.setPosition(50,20);
    this->title.setOutlineThickness(2.5);
    this->title.setOutlineColor(sf::Color(56, 56, 56));
    this->title.setFillColor(sf::Color(19, 23, 19));

    this->playBtnText.setFont(this->data->assets.getFont("Text Font"));
    this->playBtnText.setPosition((SCREEN_WIDTH/2.5) - 20 , (SCREEN_HEIGHT/4) + 75);
    this->playBtnText.setString("PLAY");
    this->playBtnText.setCharacterSize(45);
    this->playBtnText.setFillColor(sf::Color(57, 61, 50));

    this->optionsBtnText.setFont(this->data->assets.getFont("Text Font"));
    this->optionsBtnText.setPosition((SCREEN_WIDTH/2.5) - 40 , (SCREEN_HEIGHT/2) +25);
    this->optionsBtnText.setString("OPTIONS");
    this->optionsBtnText.setCharacterSize(45);
    this->optionsBtnText.setFillColor(sf::Color(57, 61, 50));

    this->exitBtnText.setFont(this->data->assets.getFont("Text Font"));
    this->exitBtnText.setPosition((SCREEN_WIDTH/2.5) - 10 , (3*SCREEN_HEIGHT/4)- 25);
    this->exitBtnText.setString("EXIT");
    this->exitBtnText.setCharacterSize(45);
    this->exitBtnText.setFillColor(sf::Color(57, 61, 50));
}
void MainmenuState::handleInput(){
    sf::Event event;
    while(this->data->window.pollEvent(event)){
        if(sf::Event::Closed == event.type){
            this->data->window.close();
        }else if(this->data->input.isTextClicked(this->exitBtnText,sf::Mouse::Left,this->data->window)){
            this->data->window.close();
        }else if(this->data->input.isTextClicked(this->playBtnText,sf::Mouse::Left,this->data->window)){
            this->data->machine.addState(GameEngine::stateRef(new PlayState(this->data)),true);
        }
    }
}
void MainmenuState::update(float dt){
    if(this->exitBtnText.getGlobalBounds().contains(this->data->input.getMousePosition(this->data->window).x,this->data->input.getMousePosition(this->data->window ).y)) {
        this->exitBtnText.setCharacterSize(47);
        this->exitBtnText.setPosition((SCREEN_WIDTH/2.5) - 12 , (3*SCREEN_HEIGHT/4)- 27);
        this->exitBtnText.setStyle(sf::Text::Style::Underlined | sf::Text::Style::Regular);
    }else{
        this->exitBtnText.setCharacterSize(45);
        this->exitBtnText.setPosition((SCREEN_WIDTH/2.5) - 10 , (3*SCREEN_HEIGHT/4)- 25);
        this->exitBtnText.setStyle(sf::Text::Style::Regular);
    }
    if(this->playBtnText.getGlobalBounds().contains(this->data->input.getMousePosition(this->data->window).x,this->data->input.getMousePosition(this->data->window ).y)){
        this->playBtnText.setPosition((SCREEN_WIDTH/2.5) - 22 , (SCREEN_HEIGHT/4) + 73);
        this->playBtnText.setCharacterSize(47);
        this->playBtnText.setStyle(sf::Text::Style::Underlined | sf::Text::Style::Regular);
    }else{
        this->playBtnText.setPosition((SCREEN_WIDTH/2.5) - 20 , (SCREEN_HEIGHT/4) + 75);
        this->playBtnText.setCharacterSize(45);
        this->playBtnText.setStyle(sf::Text::Style::Regular);
    }
    if(this->optionsBtnText.getGlobalBounds().contains(this->data->input.getMousePosition(this->data->window).x,this->data->input.getMousePosition(this->data->window ).y)){
        this->optionsBtnText.setPosition((SCREEN_WIDTH/2.5) - 42 , (SCREEN_HEIGHT/2) + 23 );
        this->optionsBtnText.setCharacterSize(47);
        this->optionsBtnText.setStyle(sf::Text::Style::Underlined | sf::Text::Style::Regular);
    }else{
        this->optionsBtnText.setPosition((SCREEN_WIDTH/2.5) - 40 , (SCREEN_HEIGHT/2) +25 );
        this->optionsBtnText.setCharacterSize(45);
        this->optionsBtnText.setStyle(sf::Text::Style::Regular);
    }
}
void MainmenuState::Draw(float dt){
    this->data->window.clear();
    this->data->window.draw(this->background);
    this->data->window.draw(this->title);
    this->data->window.draw(this->playBtnText);
    this->data->window.draw(this->exitBtnText);
    this->data->window.draw(this->optionsBtnText);
    this->data->window.display();
}