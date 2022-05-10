#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>
namespace GameEngine{
    class AssetManager{
        private:
        std::map<std::string , sf::Font> fonts;
        std::map<std::string, sf::Texture> textures;
        public:
        void LoadTexture(std::string name, std::string fileName);
        sf::Texture &getTexture(std::string name);
        void LoadFont(std::string name,std::string fileName);
        sf::Font &getFont(std::string name);
    };
}