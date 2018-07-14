#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Singleton.h"
#include "InputManager.h"
#include "World.h"

#define g_InputMng InputManager::GetInstance()

int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(800,600),"Avent");

    InputManager inputManager;

    //window.setKeyRepeatEnabled(false);
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
        window.clear(sf::Color::Black);
        window.display();

    }
    return 0;
}