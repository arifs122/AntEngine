#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {
    Clean();
}

ResourceManager& ResourceManager::Get() {
    static ResourceManager instance;
    return instance;
}

Texture2D ResourceManager::LoadTextureRes(const std::string& path) {
    if (textures.find(path) == textures.end()) {
        textures[path] = LoadTexture(path.c_str());
    }
    return textures[path];
}

Model ResourceManager::LoadModelRes(const std::string& path) {
    if (models.find(path) == models.end()) {
        models[path] = LoadModel(path.c_str());
    }
    return models[path];
}

void ResourceManager::Clean() {
    for (auto& pair : textures) {
        UnloadTexture(pair.second);
    }
    textures.clear();

    for (auto& pair : models) {
        UnloadModel(pair.second);
    }
    models.clear();
}