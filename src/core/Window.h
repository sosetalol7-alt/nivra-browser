#pragma once

#include <windows.h>

class Window
{
public:
    Window();

    bool Create(const wchar_t* title, int width, int height);

    void Show(int commandShow = SW_SHOW);

    HWND GetHandle() const;

private:
    HWND m_window;

    static LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam);
};
