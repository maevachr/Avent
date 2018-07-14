//
// Created by maeva on 11/07/18.
//

#ifndef AVENT_INPUTMANAGER_H
#define AVENT_INPUTMANAGER_H

#include <SFML/Window.hpp>
#include "Singleton.h"

class InputManager : public Singleton<InputManager>{
private:
    InputManager(const InputManager&) = delete;
    InputManager(const InputManager&&) = delete;
    InputManager operator=(const InputManager&) = delete;
    InputManager operator=(const InputManager&&) = delete;
public:
    InputManager() = default;
    void ManageMainKeyEvent (sf::Window& window, const sf::Event& event);
};


#endif //AVENT_INPUTMANAGER_H
