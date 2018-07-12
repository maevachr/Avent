#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Singleton.h"
#include "InputManager.h"
#include "World.h"

#define g_InputMng InputManager::GetSingleton()

int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::Window window(sf::VideoMode(800,600),"Avent");

    InputManager inputManager;

    //window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    g_InputMng.ManageMainKeyEvent(window, event);
                    break;
                default:
                    break;
            }
        }

    }
    return 0;
}