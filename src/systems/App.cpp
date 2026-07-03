#include"App.h"
#include"../ui/Theme.h"
#include <string>
#include <vector>
#include <raylib.h>
#include <iostream>
using namespace std;

App::App(const string& fileLocation) :
    fileManager(fileLocation), currentScene(AppScreen::LOGIN)
{}

bool App::init(){
    vector <VaultEntry> temp;
    // if () { cout << "Successful Load"; }
    // else { cout << "Loading Data Failed"; return false; }

    fileManager.LoadData(temp);

    for (size_t i = 0; i < temp.size(); i++) 
        vault.addEntry(temp[i]);

    return true;
}

bool App::shutdown(){
    if(fileManager.saveVault(vault.getVault())) {
        cout << "Saved, Closed";
        return true;
    }
    else {
        cout << "Failed to save";
        return false;
    }
}

bool App::run () {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "VaultX");
    SetTargetFPS(60);

    LoginScreen login;

    while(!WindowShouldClose()){
        BeginDrawing();

        switch (currentScene) {

            case AppScreen::LOGIN: {
                ClearBackground(BG_PRIMARY);
                currentScene = login.update();
                login.draw();
                break;
            }

            case AppScreen::DASHBOARD: {
                ClearBackground(WHITE);
                break;
            }

            case AppScreen::EDITOR: {

                break;
            }

        }

        EndDrawing();
    }

    CloseWindow();
    return true;
}

void App::addEntry(const VaultEntry& entry) {
    vault.addEntry(entry);
}