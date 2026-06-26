#include "Toolbar.h"
#include "../graphics/Renderer.h"

Toolbar::Toolbar()
{
    m_x = 0;
    m_y = 0;
    m_width = 2000;
    m_height = 80;
}

void Toolbar::Draw(Renderer& renderer)
{
    renderer.FillRectangle(
        m_x,
        m_y,
        m_width,
        m_height,
        {45, 45, 45});
}
