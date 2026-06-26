#include "UIManager.h"

#include "Widget.h"
#include "Toolbar.h"

#include <memory>

UIManager::UIManager()
{
    AddWidget(std::make_unique<Toolbar>());
}

void UIManager::Draw(Renderer& renderer)
{
    for (auto& widget : m_widgets)
    {
        widget->Draw(renderer);
    }
}

void UIManager::AddWidget(std::unique_ptr<Widget> widget)
{
    m_widgets.push_back(std::move(widget));
}
