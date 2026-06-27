#include "VaultEntry.h"
using namespace std;

VaultEntry::VaultEntry(const string& title, 
        const string& username, 
        const string& password, 
        const string& URL, 
        const string& notes, 
        const string& date, 
        const Category& category) :
        title(title),
        username(username),
        password(password),
        URL(URL),
        notes(notes),
        date(date),
        category(category) 
    {}

const string& VaultEntry::getTitle() const      {return title;}
const string& VaultEntry::getUsername() const   {return username;}
const string& VaultEntry::getPassword() const   {return password;}
const string& VaultEntry::getURL() const        {return URL;}
const string& VaultEntry::getNotes() const      {return notes;}
const string& VaultEntry::getDate() const       {return date;}
Category      VaultEntry::getCategory() const   {return category;}

void VaultEntry::setTitle(const string& title)          {this->title = title;}
void VaultEntry::setUsername(const string& username)    {this->username = username;}
void VaultEntry::setPassword(const string& password)    {this->password = password;}
void VaultEntry::setURL(const string& URL)              {this->URL = URL;}
void VaultEntry::setNotes(const string& notes)          {this->notes = notes;}
void VaultEntry::setDate(const string& date)            {this->date = date;}
void VaultEntry::setCategory(const Category& category)  {this->category = category;}

string categoryToString(Category category) {
    switch(category) {
        case Category::LOGIN:   return "LOGIN";
        case Category::WIFI:    return "WIFI";
        case Category::LICENSE: return "LICENSE";
        case Category::NOTE:    return "NOTE";
        case Category::BANKING: return "BANKING";
        case Category::OTHER:   return "OTHER";
        default:                return "OTHER";
    }
}

Category stringToCategory(const string& str) {
    if(str == "LOGIN")   return Category::LOGIN;
    if(str == "WIFI")    return Category::WIFI;
    if(str == "LICENSE") return Category::LICENSE;
    if(str == "NOTE")    return Category::NOTE;
    if(str == "BANKING") return Category::BANKING;
    return Category::OTHER;
}