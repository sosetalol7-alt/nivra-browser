#include "Application.h"
#include <windows.h>

int Application::Run()
{
    if (!m_window.Create(L"Nivra", 1280, 720))
    {
        return -1;
    }

    m_window.Show();

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}
