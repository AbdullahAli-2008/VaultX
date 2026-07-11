#pragma once
#include "Theme.h"
#include "../rlImGui/rlImGui.h"
#include "../rlImGui/imgui/imgui.h"

//Abstract Screen Class
class Screen {
public:
    Screen() {}
    virtual AppScreen update() = 0;
    virtual void draw() = 0;
    virtual ~Screen() {}
    
};