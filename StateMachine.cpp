#include "StateMachine.hpp"
#include "SFML/System.hpp"
namespace GameEngine{
    void StateMachine::addState(stateRef newState,bool isReplacing){
        this->isAdding = true;
        this->isReplacing = isReplacing;
        sf::sleep(sf::milliseconds(100));
        this->newState = std::move(newState);
    }
    void StateMachine::removeState(){
        this->isRemoving = true;
    }
    void StateMachine::processStateChanges(){
        if(this->isRemoving && !this->states.empty()){
            this->states.pop();
            if(!this->states.empty()){
                this->states.top()->Resume();
            }
            this->isRemoving = false;
        }
        if(this->isAdding){
            if(!this->states.empty()){
                if(this->isReplacing){
                    this->states.pop();
                }
                else{
                    this->states.top()->Pause();
                }
            }
            this->states.push(std::move(this->newState));
            this->states.top()->init();
            this->isAdding = false;
        }
    }
    stateRef &StateMachine::getActiveState(){
        return this->states.top();
    }
}