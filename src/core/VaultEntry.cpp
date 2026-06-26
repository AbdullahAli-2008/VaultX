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

const string& VaultEntry::getTitle()       {return title;}
const string& VaultEntry::getUsername()    {return username;}
const string& VaultEntry::getPassword()    {return password;}
const string& VaultEntry::getURL()         {return URL;}
const string& VaultEntry::getNotes()       {return notes;}
const string& VaultEntry::getDate()        {return date;}
Category      VaultEntry::getCategory()    {return category;}

void VaultEntry::setTitle(const string& title)          {this->title = title;}
void VaultEntry::setUsername(const string& username)    {this->username = username;}
void VaultEntry::setPassword(const string& password)    {this->password = password;}
void VaultEntry::setURL(const string& URL)              {this->URL = URL;}
void VaultEntry::setNotes(const string& notes)          {this->notes = notes;}
void VaultEntry::setDate(const string& date)            {this->date = date;}
void VaultEntry::setCategory(const Category& category)  {this->category = category;}

