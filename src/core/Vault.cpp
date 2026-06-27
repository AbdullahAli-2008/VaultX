#include "Vault.h"
#include <vector>
using namespace std;

Vault::Vault() {}
Vault::Vault(vector<VaultEntry>& vault) : 
vault(vault) 
{}

const vector<VaultEntry>& Vault::getVault() {return vault;}

vector<VaultEntry> Vault::searchEntries(const string& query){
    
    vector <VaultEntry> results;

    for(size_t i = 0; i < vault.size(); i++) {
        if (vault[i].getTitle().find(query) != string::npos ||
        vault[i].getUsername().find(query) != string::npos ||
        vault[i].getNotes().find(query) != string::npos
        ) 
        { results.push_back(vault[i]); }
    }

    return results;
}

void Vault::addEntry(const VaultEntry& entry)               {vault.push_back(entry);}
void Vault::deleteEntry(int index)                          {vault.erase(vault.begin() + index);}
void Vault::editEntry(int index, const VaultEntry& entry)   {vault[index] = entry;}
