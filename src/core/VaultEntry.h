#pragma once
#include <string>

enum class Category {
    LOGIN,
    WIFI,
    LICENSE,
    NOTE,
    BANKING,
    OTHER
};

class VaultEntry {
private:
    std::string title;
    std::string username;
    std::string password;
    std::string URL;
    std::string notes;
    std::string date;
    Category category;

public:
    VaultEntry(const std::string& title = "", 
        const std::string& username = "", 
        const std::string& password = "", 
        const std::string& URL = "", 
        const std::string& notes = "", 
        const std::string& date = "", 
        const Category& category = Category::OTHER);


    const std::string& getTitle();
    const std::string& getUsername();
    const std::string& getPassword();
    const std::string& getURL();
    const std::string& getNotes();
    const std::string& getDate();
    Category getCategory();

    void setTitle(const std::string& title);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setURL(const std::string& URL);
    void setNotes(const std::string& notes);
    void setDate(const std::string& date);
    void setCategory(const Category& category);
};