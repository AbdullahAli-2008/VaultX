#pragma once
#include <string>
#include "../core/Vault.h"
#include "FileManager.h"

class App {
private:
    Vault vault;
    FileManager fileManager;

public:
    App(const std::string& fileLocation = "data/vault.txt");
    bool init();
    bool run();
    bool shutdown();
};

