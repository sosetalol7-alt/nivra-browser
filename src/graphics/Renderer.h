#pragma once

#include <windows.h>
#include "Color.h"

class Renderer
{
public:
    Renderer(HDC dc);

    void Clear(const Color& color);

    void FillRectangle(
        int x,
        int y,
        int width,
        int height,
        const Color& color);

    void DrawRectangle(
        int x,
        int y,
        int width,
        int height,
        const Color& color,
        int thickness = 1);

    void DrawLine(
        int x1,
        int y1,
        int x2,
        int y2,
        const Color& color,
        int thickness = 1);

private:
    HDC m_dc;
};
