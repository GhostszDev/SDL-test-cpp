//
// Created by Mugen on 9/14/2019.
//

#ifndef TEST_CONTROLS_H
#define TEST_CONTROLS_H

#include <string>
#include <SDL2/SDL_keycode.h>
#include <map>
#include <SDL2/SDL_gamecontroller.h>
#include <iostream>
#include <SDL2/SDL_keyboard.h>
#include "../Checks/checks.h"
#include <dirent.h>
#include <vector>
#include <algorithm>

class controls {

public:
    bool setKeyBoardButton(SDL_Keycode button, std::string buttonName);
    bool setJoyStickButton(SDL_GameControllerButton button, std::string buttonName);
    static void sendButton(std::string inputKey);
    static void defineControls();
    static void move(int dir);

private:
    static void getAnimationFrames();
};


#endif //TEST_CONTROLS_H
