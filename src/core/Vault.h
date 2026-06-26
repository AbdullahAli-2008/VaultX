#pragma once
#include "VaultEntry.h"
#include <vector>

class Vault {
private:
    std::vector<VaultEntry> vault;

public:
    Vault();
    
    Vault(std::vector<VaultEntry>& vault);

    const std::vector<VaultEntry>& getVault();

    void addEntry(const VaultEntry& entry);
    void deleteEntry(int index);
    void editEntry(int index, const VaultEntry& entry);
    std::vector<VaultEntry> searchEntries(const std::string& query);
    
};