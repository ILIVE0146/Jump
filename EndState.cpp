#include"EndState.hpp"

EndState::EndState(GameEngine::GameDataRef data, int score){
    this->finalScore = score;
    this->data = data;
}
void EndState::init(){

    this->background.setTexture(this->data->assets.getTexture("Background image"));

    this->GameOverTxt.setFont(this->data->assets.getFont("Text Font"));
    this->GameOverTxt.setString("Game Over!");
    this->GameOverTxt.setCharacterSize(52);
    this->GameOverTxt.setStyle(sf::Text::Style::Bold);
    this->GameOverTxt.setPosition( (SCREEN_WIDTH/2 - this->GameOverTxt.getGlobalBounds().width/2) , 10);
    this->GameOverTxt.setFillColor(sf::Color(57, 61, 50));

    this->FinalScoreText.setFont(this->data->assets.getFont("Text Font"));
    this->FinalScoreText.setString("YOUR FINAL SCORE");
    this->FinalScoreText.setCharacterSize(48);
    this->FinalScoreText.setPosition( (SCREEN_WIDTH/2 - this->FinalScoreText.getGlobalBounds().width/2) , 120);
    this->FinalScoreText.setFillColor(sf::Color(57, 61, 50));

    this->theScoreText.setFont(this->data->assets.getFont("Text Font"));
    this->theScoreText.setString(std::to_string(this->finalScore));
    this->theScoreText.setCharacterSize(64);
    this->theScoreText.setPosition( (SCREEN_WIDTH/2 - (this->theScoreText.getGlobalBounds().width/2)) , 200);
    this->theScoreText.setFillColor(sf::Color(57, 61, 50));

    this->retryBtnTxt.setFont(this->data->assets.getFont("Text Font"));
    this->retryBtnTxt.setString("Retry");
    this->retryBtnTxt.setCharacterSize(45);
    this->retryBtnTxt.setPosition((SCREEN_WIDTH/2) - this->retryBtnTxt.getGlobalBounds().width/2 , ( 3 * SCREEN_HEIGHT/5) -20);
    this->retryBtnTxt.setFillColor(sf::Color(57, 61, 50));

    this->MainmenuBtnText.setFont(this->data->assets.getFont("Text Font"));
    this->MainmenuBtnText.setString("Main Menu");
    this->MainmenuBtnText.setCharacterSize(45);
    this->MainmenuBtnText.setPosition((SCREEN_WIDTH/2) - this->MainmenuBtnText.getGlobalBounds().width/2 , (4* SCREEN_HEIGHT/5) - 50);
    this->MainmenuBtnText.setFillColor(sf::Color(57, 61, 50));

}
void EndState::handleInput(){
    sf::Event event;
    while(this->data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->data->window.close();
        }else if(this->data->input.isTextClicked(this->retryBtnTxt,sf::Mouse::Left,this->data->window)){
            this->data->machine.addState(GameEngine::stateRef(new PlayState(this->data)),true);
        }else if(this->data->input.isTextClicked(this->MainmenuBtnText,sf::Mouse::Left,this->data->window)){
            this->data->machine.addState(GameEngine::stateRef(new MainmenuState(this->data)));
        }
    }
}
void EndState::update(float dt){
    if(this->retryBtnTxt.getGlobalBounds().contains(this->data->input.getMousePosition(this->data->window).x,this->data->input.getMousePosition(this->data->window ).y)){
        this->retryBtnTxt.setCharacterSize(47);
        this->retryBtnTxt.setPosition((SCREEN_WIDTH/2) - this->retryBtnTxt.getGlobalBounds().width/2 , ( 3 * SCREEN_HEIGHT/5) -22);
        this->retryBtnTxt.setStyle(sf::Text::Style::Underlined | sf::Text::Style::Regular);
    }else{
        this->retryBtnTxt.setCharacterSize(45);
        this->retryBtnTxt.setStyle( sf::Text::Style::Regular);
        this->retryBtnTxt.setPosition((SCREEN_WIDTH/2) - this->retryBtnTxt.getGlobalBounds().width/2 , ( 3 * SCREEN_HEIGHT/5) -20);
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
void EndState::Draw(float dt){
    this->data->window.clear();
    this->data->window.draw(this->background);
    this->data->window.draw(this->GameOverTxt);
    this->data->window.draw(this->retryBtnTxt);
    this->data->window.draw(this->FinalScoreText);
    this->data->window.draw(this->theScoreText);
    this->data->window.draw(this->MainmenuBtnText);
    this->data->window.display();
}