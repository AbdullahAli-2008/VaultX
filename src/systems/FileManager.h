#pragma once
#include "VaultEntry.h"
#include <string>
#include <vector>

class FileManager{
private:
    std::string fileName;
public:
    FileManager(const std::string& fileName);

    bool saveVault(const std::vector <VaultEntry>& vault);
    bool LoadData(std::vector <VaultEntry>& vault);
};