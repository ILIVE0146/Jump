#include"PauseState.hpp"

PauseState::PauseState(GameEngine::GameDataRef data):data(data){}
void PauseState::init(){
    this->data->assets.LoadTexture("Pause Button", PAUSEPNG);

    this->background.setTexture(this->data->assets.getTexture("Background image"));

    this->pauseTxt.setFont(this->data->assets.getFont("Text Font"));
    this->pauseTxt.setPosition( 50 , 10);
    this->pauseTxt.setString("Game Paused");
    this->pauseTxt.setCharacterSize(52);
    this->pauseTxt.setStyle(sf::Text::Style::Bold);
    this->pauseTxt.setFillColor(sf::Color(57, 61, 50));

    this->pauseSprite.setTexture(this->data->assets.getTexture("Pause Button"));
    this->pauseSprite.setPosition((SCREEN_WIDTH/2) - 70, (SCREEN_HEIGHT/5) );

    this->resumeBtnTxt.setFont(this->data->assets.getFont("Text Font"));
    this->resumeBtnTxt.setPosition((SCREEN_WIDTH/2.5) - 20 , ( 3 * SCREEN_HEIGHT/5) -20);
    this->resumeBtnTxt.setString("Resume");
    this->resumeBtnTxt.setCharacterSize(45);
    this->resumeBtnTxt.setFillColor(sf::Color(57, 61, 50));

    this->MainmenuBtnText.setFont(this->data->assets.getFont("Text Font"));
    this->MainmenuBtnText.setPosition((SCREEN_WIDTH/2.5) - 50 , (4* SCREEN_HEIGHT/5) - 50);
    this->MainmenuBtnText.setString("Main Menu");
    this->MainmenuBtnText.setCharacterSize(45);
    this->MainmenuBtnText.setFillColor(sf::Color(57, 61, 50));

}
void PauseState::handleInput(){
    sf::Event event;
    while(this->data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->data->window.close();
        }else if(this->data->input.isTextClicked(this->resumeBtnTxt,sf::Mouse::Left,this->data->window)){
            this->data->machine.removeState();
        }else if(this->data->input.isTextClicked(this->MainmenuBtnText,sf::Mouse::Left,this->data->window)){
            this->data->machine.addState(GameEngine::stateRef(new MainmenuState(this->data)));
        }
    }
}
void PauseState::update(float dt){
    if(this->resumeBtnTxt.getGlobalBounds().contains(this->data->input.getMousePosition(this->data->window).x,this->data->input.getMousePosition(this->data->window ).y)){
        this->resumeBtnTxt.setPosition((SCREEN_WIDTH/2.5) - 22 , ( 3 * SCREEN_HEIGHT/5) -22);
        this->resumeBtnTxt.setCharacterSize(47);
        this->resumeBtnTxt.setStyle(sf::Text::Style::Underlined | sf::Text::Style::Regular);
    }else{
        this->resumeBtnTxt.setPosition((SCREEN_WIDTH/2.5) - 20 , ( 3 * SCREEN_HEIGHT/5) -20);
        this->resumeBtnTxt.setCharacterSize(45);
        this->resumeBtnTxt.setStyle( sf::Text::Style::Regular);
    }
    if(this->MainmenuBtnText.getGlobalBounds().contains(this->data->input.getMousePosition(this->data->window).x,this->data->input.getMousePosition(this->data->window ).y)){
        this->MainmenuBtnText.setPosition((SCREEN_WIDTH/2.5) - 52 , (4* SCREEN_HEIGHT/5) - 52);
        this->MainmenuBtnText.setCharacterSize(47);
        this->MainmenuBtnText.setStyle(sf::Text::Style::Underlined | sf::Text::Style::Regular);
    }else{
        this->MainmenuBtnText.setPosition((SCREEN_WIDTH/2.5) - 50 , (4* SCREEN_HEIGHT/5) - 50);
        this->MainmenuBtnText.setCharacterSize(45);
        this->MainmenuBtnText.setStyle( sf::Text::Style::Regular);
    }
}
void PauseState::Draw(float dt){
    this->data->window.clear();
    this->data->window.draw(this->background);
    this->data->window.draw(this->pauseTxt);
    this->data->window.draw(this->pauseSprite);
    this->data->window.draw(this->resumeBtnTxt);
    this->data->window.draw(this->MainmenuBtnText);
    this->data->window.display();
}