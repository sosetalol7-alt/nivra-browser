#pragma once

#include <windows.h>
#include "Color.h"

class Renderer
{
public:
    explicit Renderer(HDC dc);

    void Clear(const Color& color);

    void FillRect(int x, int y, int width, int height, const Color& color);

private:
    HDC m_dc;
};
