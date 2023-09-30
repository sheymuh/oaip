﻿// лаба4.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "лаба4.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY4));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            HPEN hPen;
            hPen = CreatePen(PS_SOLID, 4, RGB(63, 72, 204));
            SelectObject(hdc, hPen);

            // Крыша
            MoveToEx(hdc, 150, 350, NULL);
            LineTo(hdc, 275, 250);
            LineTo(hdc, 400, 350);

            // Дом
            LineTo(hdc, 400, 525);
            LineTo(hdc, 150, 525);
            LineTo(hdc, 150, 350);
            LineTo(hdc, 400, 350);

            // Окно
            MoveToEx(hdc, 225, 400, NULL);
            LineTo(hdc, 225, 475);
            LineTo(hdc, 325, 475);
            LineTo(hdc, 325, 400);
            LineTo(hdc, 225, 400);
            HBRUSH hBrush;
            hBrush = CreateSolidBrush(RGB(0, 0, 255));
            SelectObject(hdc, hBrush);
            RECT rect = { 225, 475, 325, 400 };
            FillRect(hdc, &rect, hBrush);

            // Рама
            MoveToEx(hdc, 275, 400, NULL);
            LineTo(hdc, 275, 475);
            MoveToEx(hdc, 275, 425, NULL);
            LineTo(hdc, 325, 425);

            hPen = CreatePen(PS_SOLID, 3, RGB(10, 203, 204));
            SelectObject(hdc, hPen);

            // Ёлочка
            MoveToEx(hdc, 450, 525, NULL);
            LineTo(hdc, 525, 425);
            LineTo(hdc, 600, 525);
            LineTo(hdc, 450, 525);

            MoveToEx(hdc, 475, 425, NULL);
            LineTo(hdc, 525, 375);
            LineTo(hdc, 575, 425);
            LineTo(hdc, 475, 425);

            MoveToEx(hdc, 500, 375, NULL);
            LineTo(hdc, 525, 350);
            LineTo(hdc, 550, 375);
            LineTo(hdc, 500, 375);

            hPen = CreatePen(PS_SOLID, 3, RGB(32, 105, 61));
            SelectObject(hdc, hPen);

            // Дерево
            MoveToEx(hdc, 75, 525, NULL);
            LineTo(hdc, 75, 325);
            MoveToEx(hdc, 75, 505, NULL);
            LineTo(hdc, 20, 450);
            MoveToEx(hdc, 75, 465, NULL);
            LineTo(hdc, 25, 410);
            MoveToEx(hdc, 75, 425, NULL);
            LineTo(hdc, 40, 370);
            MoveToEx(hdc, 75, 385, NULL);
            LineTo(hdc, 60, 350);

            MoveToEx(hdc, 75, 485, NULL);
            LineTo(hdc, 125, 450);
            MoveToEx(hdc, 75, 445, NULL);
            LineTo(hdc, 115, 410);
            MoveToEx(hdc, 75, 405, NULL);
            LineTo(hdc, 105, 370);
            MoveToEx(hdc, 75, 360, NULL);
            LineTo(hdc, 85, 335);

            // Колодец с ведром
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 05));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 425, 275, NULL);
            LineTo(hdc, 475, 275);
            LineTo(hdc, 475, 250);
            LineTo(hdc, 425, 250);
            LineTo(hdc, 425, 275);
            hPen = CreatePen(PS_SOLID, 2, RGB(97, 64, 46));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 430, 250, NULL);
            LineTo(hdc, 430, 230);
            MoveToEx(hdc, 470, 250, NULL);
            LineTo(hdc, 470, 230);
            hPen = CreatePen(PS_SOLID, 2, RGB(99, 19, 54));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 420, 230, NULL);
            LineTo(hdc, 450, 210);
            LineTo(hdc, 480, 230);
            LineTo(hdc, 420, 230);
            hPen = CreatePen(PS_SOLID, 2, RGB(77, 77, 77));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 430, 240, NULL);
            LineTo(hdc, 475, 240);
            LineTo(hdc, 475, 245);
            LineTo(hdc, 480, 245);
            MoveToEx(hdc, 450, 240, NULL);
            LineTo(hdc, 450, 250);
            MoveToEx(hdc, 484, 275, NULL);
            LineTo(hdc, 491, 275);
            LineTo(hdc, 494, 260);
            LineTo(hdc, 481, 260);
            LineTo(hdc, 484, 275);

            //Солнце
            hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 201, 14));
            SelectObject(hdc, hBrush);
            hPen = CreatePen(PS_SOLID, 5, RGB(255, 201, 14));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 20, 20, 120, 120);

            DeleteObject(hBrush);


            DeleteObject(hPen);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
