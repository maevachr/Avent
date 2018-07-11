#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::Window window(sf::VideoMode(800,600),"Avent");
    sf::Vector2u sizeWin = window.getSize();

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
                    sizeWin = sf::Vector2u(sizeWin.x/2, sizeWin.y/2);
                    window.setSize(sizeWin);
                    break;
                default:
                    break;
            }
        }

    }
    return 0;
}