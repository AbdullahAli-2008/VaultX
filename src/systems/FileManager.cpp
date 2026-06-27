#include <fstream>
#include <sstream>
#include "FileManager.h"
#include <string>
#include <vector>
using namespace std;

    // TITLE:Netflix
    // USERNAME:myemail@gmail.com
    // PASSWORD:abc123
    // URL:netflix.com
    // NOTES:streaming account
    // CATEGORY:LOGIN
    // DATE:2024-01-15
    // ===

FileManager::FileManager(const string& fileName) :
fileName(fileName)
{}

bool FileManager::saveVault(const vector <VaultEntry>& vault) {
    ofstream file(fileName);
    if(!file.is_open()) {return false;}   

    for (size_t i = 0; i < vault.size(); i++) {
        file << "TITLE:" << vault[i].getTitle() << "\n";
        file << "USERNAME:" << vault[i].getUsername() << "\n";
        file << "PASSWORD:" << vault[i].getPassword() << "\n";
        file << "URL:" << vault[i].getURL() << "\n";
        file << "NOTES:" << vault[i].getNotes() << "\n";
        file << "CATEGORY:" << categoryToString(vault[i].getCategory()) << "\n";
        file << "DATE:" << vault[i].getDate() << "\n";
        file << "===" << "\n";
    }

    file.close();
    return true;
}

bool FileManager::LoadData(vector <VaultEntry>& vault) {
        ifstream file(fileName);
        if(!file.is_open()) {return false;}   
        string line;

        string title, username, password, url, notes, date;
        Category category = Category::OTHER;

        while(getline(file, line)) {

            if (line != "===") {
                if(line.find("TITLE:") == 0)    { title = line.substr(line.find(":") + 1); }
                if(line.find("USERNAME:") == 0) { username = line.substr(line.find(":") + 1); }
                if(line.find("PASSWORD:") == 0) { password = line.substr(line.find(":") + 1); }
                if(line.find("URL:") == 0)      { url = line.substr(line.find(":") + 1); }
                if(line.find("NOTES:") == 0)    { notes = line.substr(line.find(":") + 1); } 
                if(line.find("CATEGORY:") == 0) { category = stringToCategory(line.substr(line.find(":") + 1)); }
                if(line.find("DATE:") == 0)     { date = line.substr(line.find(":") + 1); }
            }
            else { 
                vault.push_back(VaultEntry(title, username, password, url, notes, date, category)); 
                title = username = password = url = notes = date = "";
                category = Category::OTHER;
            }
            
        }

        file.close();
        return true;
}
