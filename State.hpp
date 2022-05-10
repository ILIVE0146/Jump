#pragma once
namespace GameEngine{
    class State{
        public:
        virtual void init() = 0;
        virtual void handleInput() = 0;
        virtual void update(float dt) = 0;
        virtual void Draw(float dt) = 0;

        virtual void Pause() {}
        virtual void Resume() {}
    };
}