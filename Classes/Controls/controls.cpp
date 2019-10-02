#include "controls.h"

float moveSpeed = 0.3f;
std::map<std::string, SDL_Keycode> inputControls;
std::map<std::string, SDL_GameControllerButton> inputJoystickControls;
std::map<std::string, std::string> playerAnimation;

void controls::getAnimationFrames(){

    std::string playerPath = "../Assets/Sprites/Player/Boy/";

}

void controls::defineControls(){

    controls::getAnimationFrames();

    if(!checks::joystick()) {
        inputControls["up"] = SDLK_UP;
        inputControls["right"] = SDLK_RIGHT;
        inputControls["left"] = SDLK_LEFT;
        inputControls["down"] = SDLK_DOWN;

    } else {
        inputJoystickControls["up"] = SDL_CONTROLLER_BUTTON_DPAD_UP;
        inputJoystickControls["right"] = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
        inputJoystickControls["left"] = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
        inputJoystickControls["down"] = SDL_CONTROLLER_BUTTON_DPAD_DOWN;

        inputJoystickControls["a"] = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
        inputJoystickControls["b"] = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
        inputJoystickControls["x"] = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
        inputJoystickControls["y"] = SDL_CONTROLLER_BUTTON_DPAD_DOWN;

        inputJoystickControls["l1"] = SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
        inputJoystickControls["r1"] = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;

        inputJoystickControls["leftStick"] = SDL_CONTROLLER_BUTTON_LEFTSTICK;
        inputJoystickControls["rightStick"] = SDL_CONTROLLER_BUTTON_RIGHTSTICK;

    }
}

void controls::sendButton(std::string inputKey) {

    if(inputKey == SDL_GetKeyName(inputControls["right"])){
        move(1);
    } else if (inputKey == SDL_GetKeyName(inputControls["left"])){
        move(-1);
    }

}

void controls::move(int dir){
    float movementSpeed = dir * moveSpeed;
    std::cout << movementSpeed << std::endl;
}

bool controls::setKeyBoardButton(SDL_Keycode button, std::string buttonName) {

    if(buttonName != ""){
        inputControls[buttonName] = button;
    }

    std::cout << "Button for " << buttonName << " was not set!" << std::endl;
    return false;
}

bool controls::setJoyStickButton(SDL_GameControllerButton button, std::string buttonName) {

    if(buttonName != ""){
        inputControls[buttonName] = button;
    }

    std::cout << "Button for " << buttonName << " was not set!" << std::endl;
    return false;
}


