//
// Created by maeva on 23/06/18.
//

#ifndef AVENT_WORLD_H
#define AVENT_WORLD_H

#include <string>
#include <vector>

using std::string;

class World {
     string m_levelName;

public:
    string getName() const noexcept {
        return m_levelName;
    }
    void setName(const string& levelName) noexcept {m_levelName = levelName;}

    //void getCharacter();
    //void getObject();
};


#endif //AVENT_WORLD_H
