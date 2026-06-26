#pragma once

#include <windows.h>

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;

    COLORREF ToColorRef() const
    {
        return RGB(r, g, b);
    }
};
