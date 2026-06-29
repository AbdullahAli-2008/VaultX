#include "Screen.h"
#include <string>

class LoginScreen : public Screen {
private:
    std::string password;
    std::string passwordInput;
    bool showError;
public:
    LoginScreen();
    AppScreen update();
    void draw();
};

