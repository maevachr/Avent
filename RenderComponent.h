//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_RENDERCOMPONENT_H
#define AVENT_RENDERCOMPONENT_H


#include "Component.h"
#include "Singleton.h"
#include "HandleMgr.h"

struct tagRenderComponent{};
using HRenderComp = Handle<tagRenderComponent>;

class RenderComponentMgr: public Singleton<RenderComponentMgr> {

public:
    struct RenderComponent : public Component{
        static constexpr char* ms_TypeId = "RenderComponent";
        HGameObject m_owner;
        HRenderComp m_handle;
        const char* GetId() const override { return ms_TypeId; }

        void Update();
        const HRenderComp& GetHandle() const { return m_handle; };
        HGameObject GetOwner() const override { return m_owner; };
    };
    using HRenderCompMgr = HandleMgr<RenderComponent, HRenderComp>;
    HRenderCompMgr m_HComponents;

    // Lifetime
    RenderComponentMgr() = default;

    // Component management
    Component* CreateComponent(HGameObject hgo);
    void DeleteComponent(Component* rc);

    // Component query


};


#endif //AVENT_RENDERCOMPONENT_H
