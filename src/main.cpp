#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

wstring wndClassName(L"main");
wstring wndName(L"main");
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR nCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wc;

    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = wndClassName.c_str();
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.cbClsExtra = NULL;
    wc.cbWndExtra = NULL;
    wc.lpszMenuName = NULL;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if(!RegisterClass(&wc)) return 0;

    hWnd = CreateWindow(wndClassName.c_str(), wndName.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                         800, 600, NULL, NULL, hInstance, NULL);
    
    ShowWindow(hWnd, nCmdShow);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        default:
         return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}