#pragma once
#include <string>
#include "../core/Vault.h"
#include "FileManager.h"
#include "../ui/LoginScreen.h"
#include "../ui/Theme.h"

class App {
private:
    Vault vault;
    FileManager fileManager;
    AppScreen currentScene;

public:
    App(const std::string& fileLocation = "data/vault.txt");
    bool init();
    bool run();
    bool shutdown();
    void addEntry(const VaultEntry& entry);
};


