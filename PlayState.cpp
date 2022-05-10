#include "PlayState.hpp"
PlayState::PlayState(GameEngine::GameDataRef data):data(data){}
void PlayState::init(){
    this->score = 0;

    this->scoreText.setFont(this->data->assets.getFont("Text Font"));
    this->scoreText.setFillColor(sf::Color(0,0,0));
    this->scoreText.setString("SCORE: 0");
    this->rectForScore.setSize(sf::Vector2f(this->scoreText.getGlobalBounds().width + 5, this->scoreText.getGlobalBounds().height + 5));
    this->rectForScore.setFillColor(sf::Color(54, 60, 69,102));

    this->background.setTexture(this->data->assets.getTexture("Background image"));
    for(int i = 0; i < 5 ; i++){
        this->ledge[i].setTexture(this->data->assets.getTexture("Ledge image"));
    }
    this->ball.setTexture(this->data->assets.getTexture("ball image"));
    this->ball.setScale(1.5,1.5);
    srand(time(0));
    this->x = 100.0f;
    this->y = 100.0f;
    this->h = 200.0f;
    this->dx = 0.0f;
    this->dy = 0.0f;
    this->speed = 400.0f;
    for(int i=0;i<5;i++){
        this->platform[i].x = rand()%(400 - ((int)this->ledge[i].getGlobalBounds().width - 5)) ;
        this->platform[i].y = (i*100) + 11;
    }
}
void PlayState::handleInput(){
    sf::Event event;
    while(this->data->window.pollEvent(event)){
        if(sf::Event::Closed == event.type ){
            this->data->window.close();
        }
        
    }
}
void PlayState::update(float dt){
    if(this->data->input.isKeyPressed(sf::Keyboard::Escape)){
        this->data->machine.addState(GameEngine::stateRef(new PauseState(this->data)),false);
    }
    this->dy += 0.2;
    this->y += this->dy;
    if(this->y > 533){
        //gameOver
        this->data->machine.addState(GameEngine::stateRef(new EndState(this->data,this->score)),true);
    }
    if(this->y < this->h){
        for (int i = 0; i < 5; i++) {
            this->y = this->h;
            this->platform[i].y = this->platform[i].y - this->dy;
            if(this->platform[i].y > 533){ 
                this->platform[i].y = 0; 
                this->platform[i].x = rand()%(400 - (int)this->ledge[i].getGlobalBounds().width);
                this->score += 1;
            }
        }
    }
    if(this->data->input.isKeyPressed(sf::Keyboard::Left)){
        this->x -= speed * dt;
    }else if(this->data->input.isKeyPressed(sf::Keyboard::Right)){
        this->x += speed * dt;
    }
    for(int i = 0; i < 5; i++){
        // if ((this->x + 50 > this->platform[i].x) && (this->x + 20 < this->platform[i].y + 68) && (this->y + 70 > platform[i].y) && (this->y + 70 < this->platform[i].y + 14) && (this->dy > 0)) {
        //     this->dy = -10;
        // }
        if(this->ledge[i].getGlobalBounds().intersects(this->ball.getGlobalBounds())){
            this->dy = -10;
        }
    }
    if(this->x > 400 - this->ball.getGlobalBounds().width){
        this->x = 400 - this->ball.getGlobalBounds().width;
    }else if(this->x < 0){
        this->x = 0;
    }
    ball.setPosition(this->x,this->y);
    for (int i = 0; i < 5; i++){
        this->ledge[i].setPosition(this->platform[i].x, this->platform[i].y);
    }
    this->scoreText.setString("SCORE: " + std::to_string(score));
    this->rectForScore.setSize(sf::Vector2f(this->scoreText.getGlobalBounds().width + 5, this->scoreText.getGlobalBounds().height + 5));
}
void PlayState::Draw(float dt){
    this->data->window.clear();
    this->data->window.draw(this->background);
    this->data->window.draw(this->ball);
    for(int i=0;i<5;i++){
        this->data->window.draw(this->ledge[i]);
    }
    this->data->window.draw(this->rectForScore);
    this->data->window.draw(this->scoreText);
    this->data->window.display();
}