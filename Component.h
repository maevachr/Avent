//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_COMPONENT_H
#define AVENT_COMPONENT_H


#include "GameObject.h"

class Component {
public:
    virtual ~Component() = default;
    virtual HGameObject GetOwner() const = 0;

    // register to corresponding Manager and add Owner
    virtual void OnAttached(HGameObject hgo) = 0;
    // unregister to corresponding manager
    virtual void OnDetached() = 0;
};


#endif //AVENT_COMPONENT_H
