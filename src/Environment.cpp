#include <vector>
#include "Environment.hpp"

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
    for (StaticObject* obj : obstacles) {
        obj->Draw();
    }
}
void Environment::AddObject(Vector3 pos){
    BoundingBox box = GetModelBoundingBox(blockModel);
    StaticObject* newObj = new StaticObject(false, pos, 0.0f, blockModel, box);
    obstacles.push_back(newObj);
}
void Environment::Clean(){
    for (StaticObject* obj : obstacles) {
        delete obj;
    }

    obstacles.clear();
    UnloadModel(blockModel);
}
