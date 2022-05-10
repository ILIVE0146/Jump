#pragma once
#include "State.hpp"
#include <stack>
#include <memory>
namespace GameEngine{
    typedef std::unique_ptr<State> stateRef;
    class StateMachine{
        private:
        std::stack<stateRef> states;
        stateRef newState;
        bool isRemoving, isAdding, isReplacing;
        public:
        void addState(stateRef newState, bool isReplacing = true);
        void removeState();
        void processStateChanges();
        stateRef &getActiveState();
    };
}