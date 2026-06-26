#include "Window.h"

Window::Window()
    : m_window(nullptr)
{
}

bool Window::Create(const wchar_t* title, int width, int height)
{
    const wchar_t CLASS_NAME[] = L"NivraWindowClass";

    WNDCLASSW wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    RegisterClassW(&wc);

    m_window = CreateWindowExW(
        0,
        CLASS_NAME,
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        nullptr,
        nullptr,
        GetModuleHandleW(nullptr),
        nullptr
    );

    return m_window != nullptr;
}

void Window::Show(int commandShow)
{
    ShowWindow(m_window, commandShow);
    UpdateWindow(m_window);
}

HWND Window::GetHandle() const
{
    return m_window;
}

LRESULT CALLBACK Window::WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
}
