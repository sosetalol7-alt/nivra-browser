#pragma once

class Renderer;

class Widget
{
public:
    virtual ~Widget() = default;

    virtual void Draw(Renderer& renderer) = 0;

    virtual void Update() {}

    virtual void OnMouseMove(int x, int y) {}

    virtual void OnMouseDown(int x, int y) {}

    virtual void OnMouseUp(int x, int y) {}

protected:
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;
};
