#include "LoginScreen.h"
#include <cstring>
#include <iostream>
using namespace ImGui;
using namespace std;

float LogoScale = 0.5;
float LockScale = 0.1;

LoginScreen::LoginScreen() {
    strcpy(password, "password123");
    strcpy(passwordInput, "");
    showError = false;
    lock = LoadTexture("assets/lock.png");
    logo = LoadTexture("assets/vault_backgroundless.png");
    lockHitBox = {(float)(3 * GetScreenWidth())/4, (float)GetScreenHeight()/2, lock.width * LockScale, lock.height * LockScale};
    flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNav;
}   

AppScreen LoginScreen::update(){

    //Enter/LockTouched
    lockHitBox = {(float)(3 * GetScreenWidth())/4, (float)GetScreenHeight()/2, lock.width * LockScale, lock.height * LockScale};

    if(IsKeyPressed(KEY_ENTER) || (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), lockHitBox))) 
    {
        if(!strcmp(password, passwordInput)) {
            return AppScreen::DASHBOARD;
        }
        else {
            showError = true;
        }
    }
    return AppScreen::LOGIN;
}

void LoginScreen::draw(){
    Rectangle rec = {0,0, (float)GetScreenWidth(), (float)GetScreenHeight()};
    DrawRectangleGradientEx(rec, BG_PRIMARY, BG_SURFACE, BG_SURFACE, BG_PRIMARY);
    DrawTextureEx(logo, {0,0}, 0, LogoScale, WHITE);

    if(!CheckCollisionPointRec(GetMousePosition(), lockHitBox)){
        DrawCircleGradient((float)(3 * GetScreenWidth())/4 + (lock.width * LockScale) / 2, (float)GetScreenHeight()/2 + (lock.height * LockScale) / 2 + 10, 30, WHITE, BLANK);
        DrawTextureEx(lock, {(float)(3 * GetScreenWidth())/4 , (float)GetScreenHeight()/2}, 0, LockScale, WHITE);
    }
    else {
        DrawCircleGradient((float)(3 * GetScreenWidth())/4 + (lock.width * LockScale) / 2, (float)GetScreenHeight()/2 + (lock.height * LockScale) / 2 + 10, 50, WHITE, BLANK);
        DrawTextureEx(lock, {(float)(3 * GetScreenWidth())/4 - (float)(lock.width * (LockScale + 0.02) - lock.width * LockScale)/2, (float)GetScreenHeight()/2 - (float)(lock.height * (LockScale + 0.02) - lock.height * LockScale)/2}, 0, LockScale + 0.02, WHITE);
    }
    if(showError) {
        DrawText("Incorrect password", 20, GetScreenHeight() - 20, 15, DANGER);
    }


    SetNextWindowSize(ImVec2(GetScreenWidth(), GetScreenHeight()));
    SetNextWindowPos(ImVec2(0, 0));

    Begin("LoginScreen", NULL, flags);
        SetWindowFontScale(2.0f);
        SetCursorPos(ImVec2(GetScreenWidth()/2 - GetScreenWidth()/10, GetScreenHeight()/2 - GetScreenHeight()/20));
        SetNextItemWidth(GetScreenWidth()/5);
        InputTextWithHint("##Password_field", "Enter Password", passwordInput, 17, ImGuiInputTextFlags_Password);
    End();
}

LoginScreen::~LoginScreen(){
    UnloadTexture(logo);
    UnloadTexture(lock);
}