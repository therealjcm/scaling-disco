//
// Created by jasonm on 10/14/2016.
//

#include "AssetManager.h"
#include <assert.h>

AssetManager *AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture & AssetManager::GetTexture(std::string const &filename)
{
    auto &textMap = sInstance->m_Textures;

    auto pairFound = textMap.find(filename);
    if (pairFound != textMap.end())
    {
        // texture already mapped, go ahead and return it
        return pairFound->second;
    }
    else
    {
        // load texture and map it, then return it
        auto &texture = textMap[filename]; // create entry point in map
        texture.loadFromFile(filename);
        return texture;
    }
}
