//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_COMPONENT_H
#define AVENT_COMPONENT_H


#include <string>
#include "Handle.h"

class GameObject;
struct tagGameObject{};
using HGameObject = Handle<tagGameObject>;

class Component {
public:
    static constexpr char *ms_TypeId = "Component";
    virtual ~Component() = default;
    virtual HGameObject GetOwner() const = 0;
    virtual const char* GetId() const { return Component::ms_TypeId;}
};

;

#endif //AVENT_COMPONENT_H
