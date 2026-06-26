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

void Renderer::FillRectangle(
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

void Renderer::DrawRectangle(
    int x,
    int y,
    int width,
    int height,
    const Color& color,
    int thickness)
{
    HPEN pen = CreatePen(PS_SOLID, thickness, color.ToColorRef());

    HGDIOBJ oldPen = SelectObject(m_dc, pen);
    HGDIOBJ oldBrush = SelectObject(m_dc, GetStockObject(NULL_BRUSH));

    Rectangle(
        m_dc,
        x,
        y,
        x + width,
        y + height);

    SelectObject(m_dc, oldBrush);
    SelectObject(m_dc, oldPen);

    DeleteObject(pen);
}

void Renderer::DrawLine(
    int x1,
    int y1,
    int x2,
    int y2,
    const Color& color,
    int thickness)
{
    HPEN pen = CreatePen(PS_SOLID, thickness, color.ToColorRef());

    HGDIOBJ oldPen = SelectObject(m_dc, pen);

    MoveToEx(m_dc, x1, y1, nullptr);
    LineTo(m_dc, x2, y2);

    SelectObject(m_dc, oldPen);

    DeleteObject(pen);
}
