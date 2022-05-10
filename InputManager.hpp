#pragma once
#include <SFML/Graphics.hpp>

namespace GameEngine{
    class InputManager{
        public:
        bool isKeyPressed(sf::Keyboard::Key key);
        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i getMousePosition(sf::RenderWindow &window);
        bool isTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow &window );
    };
}