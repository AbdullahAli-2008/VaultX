#include"App.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

App::App(const string& fileLocation) :
    fileManager(fileLocation)
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
    return true;
}

void App::addEntry(const VaultEntry& entry) {
    vault.addEntry(entry);
}