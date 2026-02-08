#include <vector>
#include "Environment.hpp"
#include "Player.hpp"

Environment::Environment(){}

Environment::~Environment(){
    Clean();
}

//load models(no models for now)
void Environment::Init(){

    Mesh mesh = GenMeshCube(2.0f, 2.0f, 2.0f);
    

    blockModel = LoadModelFromMesh(mesh);


    blockModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = RED;


    AddObject({-5.0f, 0.5f, 5.0f}); 
    AddObject({ 5.0f, 0.5f, 5.0f}); 
    AddObject({ 0.0f, 0.5f, 10.0f}); 
}

void Environment::Update(){}

void Environment::Draw(){
    for (const auto& obj : obstacles) {
        obj->Draw();
    }
}
void Environment::AddObject(Vector3 pos){
    BoundingBox box = GetModelBoundingBox(blockModel);
    BoundingBox worldBox;
    worldBox.min = Vector3Add(box.min, pos);
    worldBox.max = Vector3Add(box.max, pos);
    obstacles.push_back(std::make_unique<StaticObject>(false, pos, 0.0f, blockModel, worldBox));
}
void Environment::Clean(){
    obstacles.clear();
    UnloadModel(blockModel);
}
bool Environment::HandleCollision(Vector3 futurePos,BoundingBox collisionBox){
    BoundingBox phantomBox;

    phantomBox.min = Vector3Add(collisionBox.min, futurePos);
    phantomBox.max = Vector3Add(collisionBox.max, futurePos);
    phantomBox.min.y += 0.1f;
    phantomBox.max.y += 0.1f;

    for (const auto& obj : obstacles)
    {
        if (CheckCollisionBoxes(obj->collisionBox,phantomBox))
        {
            return true;
        }
        
    }
    return false;
}

void Environment::DrawDebug() {
    for (const auto& obj : obstacles) {
        // Her objenin çarpışma kutusunu YEŞİL tel kafes olarak çiz
        DrawBoundingBox(obj->collisionBox, GREEN);
    }
}
