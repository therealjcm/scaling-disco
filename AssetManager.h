//
// Created by jasonm on 10/14/2016.
//

#ifndef SCALING_DISCO_ASSETMANAGER_H
#define SCALING_DISCO_ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager {
public:
    AssetManager();

    static sf::Texture & GetTexture(std::string const &filename);

private:
    std::map<std::string, sf::Texture> m_Textures;

    // singleton
    static AssetManager *sInstance;
};


#endif //SCALING_DISCO_ASSETMANAGER_H
