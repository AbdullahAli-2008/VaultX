#pragma once
#include "VaultEntry.h"
#include <string>
#include <vector>

class FileManager{
private:
    std::string fileName;
public:
    FileManager(std::string& fileName);

    void saveVault(const std::vector <VaultEntry>& vault);
    const std::vector <VaultEntry> LoadData();
};