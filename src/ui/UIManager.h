#pragma once

#include <memory>
#include <vector>

#include "Widget.h"

class Renderer;

class UIManager
{
public:
    UIManager();

    void Draw(Renderer& renderer);

    void AddWidget(std::unique_ptr<Widget> widget);

private:
    std::vector<std::unique_ptr<Widget>> m_widgets;
};
