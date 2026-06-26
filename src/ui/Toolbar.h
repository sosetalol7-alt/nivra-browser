#pragma once

#include "Widget.h"

class Toolbar : public Widget
{
public:
    Toolbar();

    void Draw(Renderer& renderer) override;
};
