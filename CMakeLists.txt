cmake_minimum_required(VERSION 3.10)
project(Avent)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

set(SOURCE_FILES World.cpp World.h InputManager.cpp InputManager.h Singleton.cpp Singleton.h main.cpp Handle.cpp Handle.h HandleMgr.cpp HandleMgr.h GameObject.cpp GameObject.h Component.cpp Component.h)
add_executable(Avent ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Avent ${SFML_LIBRARIES})
endif ()