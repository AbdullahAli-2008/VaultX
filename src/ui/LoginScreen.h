#pragma once
#include "Screen.h"
#include <string>

class LoginScreen : public Screen {
private:
    char password[17];
    char passwordInput[17];
    ImGuiWindowFlags flags;
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

