//
// Created by maeva on 11/07/18.
//

#include "InputManager.h"

void InputManager::ManageMainKeyEvent (sf::Window& window, const sf::Event& event){

    sf::Vector2u sizeWin = window.getSize();
    switch (event.key.code){
        case sf::Keyboard::O :
            if(sizeWin.x > 1 && sizeWin.y > 1){
                sizeWin = sf::Vector2u(sizeWin.x/2, sizeWin.y/2);
                window.setSize(sizeWin);
            }
            break;
        case sf::Keyboard::P :
            sizeWin = sf::Vector2u(sizeWin.x*2, sizeWin.y*2);
            window.setSize(sizeWin);
            break;
        default:
            break;
    }
}
