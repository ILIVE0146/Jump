#include"AssetManager.hpp"

namespace GameEngine{
    void AssetManager::LoadTexture(std::string name, std::string fileName){
        sf::Texture tex;
        if(tex.loadFromFile(fileName)){
            tex.setSmooth(true);
            this->textures[name] = tex;
        }else{
            std::cerr<<"Out of range error: "<<fileName<<" file not found!"<<std::endl;
            system("pause");
            abort();
        }
    }
    sf::Texture &AssetManager::getTexture(std::string name){
        try{
            return this->textures.at(name);
        }
        catch(std::out_of_range& oor){
            std::cerr<<"Out of range error: "<<name<<" texture not found!"<<std::endl;
            system("pause");
            abort();
        }
    }
    void AssetManager::LoadFont(std::string name, std::string fileName){
        sf::Font font;
        if(font.loadFromFile(fileName)){
            this->fonts[name] = font;
        }else{
            std::cerr<<"Out of range error: "<<fileName<<" file not found!"<<std::endl;
            system("pause");
            abort();
        }
    }
    sf::Font &AssetManager::getFont(std::string name){
        try{
            return this->fonts.at(name);
        }
        catch(std::out_of_range& oor){
            std::cerr<<"Out of range error: "<<name<<" Font not found to return!"<<std::endl;
            system("pause");
            abort();
        }
    }
}