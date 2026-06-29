#pragma once
#include "raylib.h"

// Color Pal

const Color BG_PRIMARY    = {12, 12, 18, 255};    // near black with blue tint
const Color BG_SURFACE    = {20, 20, 32, 255};    // slightly lighter panels
const Color BG_BORDER     = {40, 40, 60, 255};    // subtle borders
const Color TEXT_PRIMARY  = {220, 220, 230, 255}; // soft white
const Color TEXT_SECONDARY= {120, 120, 140, 255}; // muted grey
const Color ACCENT        = {88, 86, 214, 255};   // deep purple
const Color DANGER        = {220, 60, 60, 255};   // red for delete

//  App Screen

enum class AppScreen {
    LOGIN,
    DASHBOARD,
    EDITOR
};