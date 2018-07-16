//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_GAMEOBJECT_H
#define AVENT_GAMEOBJECT_H

#include <string>
#include "Handle.h"
#include "HandleMgr.h"
#include "Singleton.h"

struct tagGameObject{};
using HGameObject = Handle<tagGameObject>;

class GameObjectMgr : public Singleton<GameObjectMgr>{
    struct GameObject{
        std::string m_Name;
        void OnSpawn();
        void OnUnspawn();
    };

    using HGameObjectMgr = HandleMgr<GameObject, HGameObject>;
    HGameObjectMgr m_GameObjects;
public:
    GameObjectMgr(){}
    ~GameObjectMgr();

    // Game object management
    HGameObject CreateGameObject(std::string name = "");
    void DeleteGameObject(HGameObject hgo);

    // Game object query
    const std::string& GetName(const HGameObject& hgo) const{ return (m_GameObjects.Dereference(hgo))->m_Name;}
};


#endif //AVENT_GAMEOBJECT_H
