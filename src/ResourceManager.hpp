#pragma once
#include "raylib.h"
#include <string>
#include <unordered_map>

class ResourceManager {
private:
    std::unordered_map<std::string, Texture2D> textures;
    std::unordered_map<std::string, Model> models;

    ResourceManager();
    ~ResourceManager();

public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    static ResourceManager& Get();

    Texture2D LoadTextureRes(const std::string& path);
    Model LoadModelRes(const std::string& path);

    void Clean();
};