#include "LoginScreen.h"
using namespace std;

float LogoScale = 0.5;
float LockScale = 0.1;

LoginScreen::LoginScreen() {
    password = "password123";
    passwordInput = "";
    showError = false;
    lock = LoadTexture("assets/lock.png");
    logo = LoadTexture("assets/vault_backgroundless.png");
    lockHitBox = {(float)(3 * GetScreenWidth())/4, (float)GetScreenHeight()/2, lock.width * LockScale, lock.height * LockScale};
}

AppScreen LoginScreen::update(){

    //Enter/LockTouched
    lockHitBox = {(float)(3 * GetScreenWidth())/4, (float)GetScreenHeight()/2, lock.width * LockScale, lock.height * LockScale};

    if(IsKeyPressed(KEY_ENTER) || (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), lockHitBox))) 
    {
        //We Compare here
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
}

LoginScreen::~LoginScreen(){
    UnloadTexture(logo);
    UnloadTexture(lock);
}