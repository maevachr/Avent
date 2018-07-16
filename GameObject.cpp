//
// Created by maeva on 16/07/18.
//

#include "GameObject.h"

GameObjectMgr::~GameObjectMgr() {

}

HGameObject GameObjectMgr::CreateGameObject(std::string name) {
    HGameObject hgo = HGameObject{};
    GameObject* go = m_GameObjects.Acquire(hgo);
    go->m_Name = name;
    return hgo;
}

void GameObjectMgr::DeleteGameObject(HGameObject hgo) {
    m_GameObjects.Release(hgo);
}