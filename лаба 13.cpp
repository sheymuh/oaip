// лаба 13.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "лаба 13.h"

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
    LoadStringW(hInstance, IDC_MY13, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY13));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY13));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY13);
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

// ЗАДАЧА 1
void Image0(HDC hdc, int cx, int cy, COLORREF color) {

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,        	cy + 20,
        cx + 20,	cy - 20,
        cx - 20,   	cy - 20,
        cx,        	cy + 20
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}

// ЗАДАЧА 2
void Image1(HDC hdc, int cx, int cy, COLORREF color) {

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,        	cy - 20,
        cx + 20,	cy + 20,
        cx - 20,   	cy + 20,
        cx,        	cy - 20
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}

// ЗАДАЧА 3
void PictureV(HDC hdc) {
    int x, y, i;

    x = 100;
    y = 50;
    i = 0;
    do {

        Image0(hdc, x, y, RGB(0, 255, 0));
        y += 70;

        i++;
    } while (i < 6);
}

// ЗАДАЧА 4
void PictureH(HDC hdc) {
    int x, y, j;

    x = 100;
    y = 50;
    j = 0;
    do {

        Image0(hdc, x, y, RGB(255, 0, 0));
        x += 50;

        j++;
    } while (j < 8);
}

// ЗАДАЧА 5
void PictureVH(HDC hdc) {
    int x, y, i, j;

    y = 50;
    i = 0;
    do {

        x = 100;
        j = 0;
        do {
            Image0(hdc, x, y, RGB(255, 255, 0));
            x += 50;

            j++;
        } while (j < 8);

        y += 70;

        i++;
    } while (i < 6);
}

// ЗАДАНИЕ 8*
void PictureV2H2(HDC hdc) {

    int x, y, i, j;
    unsigned char r, g;
    y = 150;
    i = 0;
    g = 0;

    do {
        x = 800;
        j = 0;
        r = 0;
        
        do {
            Image0(hdc, x, y, RGB(r, g, 0));
            x += 50;
            r += 36;

            j++;
        } while (j < 8);

        y += 70;
        g += 51;

        i++;
    } while (i < 6);
}
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

            Image0(hdc, 530, 30, RGB(213, 342, 312));
            Image0(hdc, 530, 130, RGB(523, 873, 656));
            Image0(hdc, 530, 230, RGB(788, 865, 523));

            Image1(hdc, 580, 30, RGB(533, 123, 645));
            Image1(hdc, 580, 130, RGB(570, 243, 987));
            Image1(hdc, 580, 230, RGB(124, 432, 763));

            PictureV(hdc);

            PictureH(hdc);

            PictureVH(hdc);

            PictureV2H2(hdc);

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
