#pragma once
#include "Screen.h"
#include <string>

class LoginScreen : public Screen {
private:
    std::string password;
    std::string passwordInput;
    bool showError;
    Texture2D logo;
    Texture2D lock;
    Rectangle lockHitBox;
    
public:
    LoginScreen();
    AppScreen update();
    void draw();
    ~LoginScreen();
};

