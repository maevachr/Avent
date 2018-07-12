//
// Created by maeva on 11/07/18.
//

#ifndef AVENT_INPUTMANAGER_H
#define AVENT_INPUTMANAGER_H

#include <SFML/Window.hpp>
#include "Singleton.h"

class InputManager : public Singleton<InputManager>{
    public:
    void ManageMainKeyEvent (sf::Window& window, const sf::Event& event){

        sf::Vector2u sizeWin = window.getSize();
        sizeWin = sf::Vector2u(sizeWin.x/2, sizeWin.y/2);
        window.setSize(sizeWin);
    }
};


#endif //AVENT_INPUTMANAGER_H
