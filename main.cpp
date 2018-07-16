#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Singleton.h"
#include "InputManager.h"
#include "World.h"
#include "GameObject.h"

#define g_InputMng InputManager::GetInstance()
#define g_GOMng GameObjectMgr::GetInstance()

int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(800,600),"Avent");

    InputManager inputManager;
    GameObjectMgr gameObjectMgr;

    HGameObject hero = g_GOMng.CreateGameObject("hero");
    std::cout << hero.GetIndex() << " : " << g_GOMng.GetName(hero) << std::endl;
    g_GOMng.DeleteGameObject(hero);


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