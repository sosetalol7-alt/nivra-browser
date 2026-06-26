#include "Renderer.h"

Renderer::Renderer(HDC dc)
    : m_dc(dc)
{
}

void Renderer::Clear(const Color& color)
{
    RECT rect;

    GetClipBox(m_dc, &rect);

    HBRUSH brush = CreateSolidBrush(color.ToColorRef());

    ::FillRect(m_dc, &rect, brush);

    DeleteObject(brush);
}

void Renderer::FillRect(
    int x,
    int y,
    int width,
    int height,
    const Color& color)
{
    RECT rect =
    {
        x,
        y,
        x + width,
        y + height
    };

    HBRUSH brush = CreateSolidBrush(color.ToColorRef());

    ::FillRect(m_dc, &rect, brush);

    DeleteObject(brush);
}
