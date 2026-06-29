#pragma once
#include "Theme.h"

//Abstract Screen Class
class Screen {
public:
    Screen() {}
    virtual AppScreen update() = 0;
    virtual void draw() = 0;
    virtual ~Screen() {}
};