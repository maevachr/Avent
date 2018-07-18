//
// Created by maeva on 16/07/18.
//

#include "RenderComponent.h"

Component* RenderComponentMgr::CreateComponent(HGameObject hgo) {
    HRenderComp hrc = HRenderComp{};
    RenderComponent* rc = m_HComponents.Acquire(hrc);
    rc->m_handle = hrc;
    rc->m_owner = hgo;
    return static_cast<Component*>(rc);
}

void RenderComponentMgr::DeleteComponent(Component* rc) {
    HRenderComp hrc = static_cast<RenderComponent*>(rc)->m_handle;
    m_HComponents.Release(hrc);
}