//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_GAMEOBJECT_H
#define AVENT_GAMEOBJECT_H

#include <string>
#include <algorithm>
#include <cstring>
#include "Handle.h"
#include "HandleMgr.h"
#include "Singleton.h"
#include "Component.h"
#include "RenderComponent.h"



class GameObjectMgr : public Singleton<GameObjectMgr>{
    struct GameObject{
        std::string m_Name;
        std::vector<Component*> m_Components;
        void OnSpawn();
        void OnUnspawn();
    };

    using HGameObjectMgr = HandleMgr<GameObject, HGameObject>;
    HGameObjectMgr m_GameObjects;
public:
    GameObjectMgr() = default;

    // Game object management
    HGameObject CreateGameObject(const std::string& name = "");
    void DeleteGameObject(HGameObject hgo);

    // Components
    template<typename COMP, typename COMP_MGR>
    std::enable_if_t<std::is_base_of<Component, COMP>::value> CreateComponent(HGameObject hgo);
    template<typename COMP, typename COMP_MGR>
    std::enable_if_t<std::is_base_of<Component, COMP>::value> RemoveComponent(HGameObject hgo);
    template <typename COMP>
    std::enable_if_t<std::is_base_of<Component, COMP>::value, std::vector<Component*>::iterator> FindComponent(HGameObject);
    bool IsNull(std::vector<Component*>::iterator it, HGameObject hgo){
        return it == m_GameObjects.Dereference(hgo)->m_Components.end();
    }


    // Game object query
    const std::string& GetName(const HGameObject& hgo) const{ return (m_GameObjects.Dereference(hgo))->m_Name;}
};

using RenderComponent = RenderComponentMgr::RenderComponent;

template<typename COMP, typename COMP_MGR>
std::enable_if_t<std::is_base_of<Component, COMP>::value> GameObjectMgr::CreateComponent(HGameObject hgo){
    COMP_MGR& comp_mgr = COMP_MGR::GetInstance();
    Component* comp = comp_mgr.CreateComponent(hgo);
    //COMP_MGR::GetInstance().m_HComponents.Acquire(static_cast<COMP*>(comp)->m_handle);
    m_GameObjects.Dereference(hgo)->m_Components.push_back(comp);
}

template <typename COMP>
std::enable_if_t<std::is_base_of<Component, COMP>::value, std::vector<Component*>::iterator> GameObjectMgr::FindComponent(HGameObject hgo) {
    GameObject *go = m_GameObjects.Dereference(hgo);
    using CompVec = std::vector<Component*>;
    CompVec &v_components = go->m_Components;
    CompVec::iterator it = std::find_if(v_components.begin(), v_components.end(), [](Component *comp) {
        bool res = std::strcmp(comp->GetId(), COMP::ms_TypeId) == 0; // 0 if strings are the same
        return res;
    });
    return it;
}

template<typename COMP, typename COMP_MGR>
std::enable_if_t<std::is_base_of<Component, COMP>::value> GameObjectMgr::RemoveComponent(HGameObject hgo){
    using CompVecIt = std::vector<Component*>::iterator;
    CompVecIt comp = FindComponent<COMP>(hgo);
    if(comp != m_GameObjects.Dereference(hgo)->m_Components.end()){
        // Release the resource
        COMP_MGR& comp_mgr = COMP_MGR::GetInstance();
        comp_mgr.DeleteComponent(*comp);

        // Remove from the list of commponent of the GameObject
        GameObject *go = m_GameObjects.Dereference(hgo);

        //COMP_MGR::GetInstance().m_HComponents.Release(static_cast<COMP*>(*comp)->m_handle);
        go->m_Components.erase(comp);
    }
}

#endif //AVENT_GAMEOBJECT_H
