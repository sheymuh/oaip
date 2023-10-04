// лаба7.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "лаба7.h"

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
    LoadStringW(hInstance, IDC_MY7, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY7));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY7);
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
            hBrush = CreateSolidBrush(RGB(30, 95, 255));
            SelectObject(hdc, hBrush);
            RECT rect = { 225, 475, 325, 400 };
            FillRect(hdc, &rect, hBrush);

            // Рама
            MoveToEx(hdc, 275, 400, NULL);
            LineTo(hdc, 275, 475);
            MoveToEx(hdc, 275, 425, NULL);
            LineTo(hdc, 325, 425);

            // Ёлочка
            hPen = CreatePen(PS_SOLID, 3, RGB(20, 105, 0));
            SelectObject(hdc, hPen);

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

            // Куст 1
            hPen = CreatePen(PS_SOLID, 3, RGB(34, 177, 76));
            SelectObject(hdc, hPen);

            int x1 = 400, y1 = 150;
            int x2 = 500, y2 = 250;

            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 25;
            } while (x1 <= 600);

           // Куст 2
            {
                hPen = CreatePen(PS_SOLID, 3, RGB(228, 140, 255));
                SelectObject(hdc, hPen);

                int w1 = 0, z1 = 250;
                int w2 = 100, z2 = 250;
                do {
                    MoveToEx(hdc, w1, z1, NULL);
                    LineTo(hdc, w2, z2);

                    w1 += 25;
                    z1 -= 50;
                } while (w1 <= 100);

                w1 = 100;
                z1 = 50;

                do {
                    MoveToEx(hdc, w1, z1, NULL);
                    LineTo(hdc, w2, z2);

                    w1 += 25;
                    z1 += 50;
                } while (w1 <= 200);
            }

            // Забор
            hPen = CreatePen(PS_SOLID, 3, RGB(255, 181, 22));
            SelectObject(hdc, hPen);

            int a1 = 150, b1 = 0;
            int a2 = 150, b2 = 100;

            do {
                MoveToEx(hdc, a1, b1, NULL);
                LineTo(hdc, a2, b2);

                a1 += 25;
                a2 += 25;
            } while (a1 <= 450);

            // Трава
            hPen = CreatePen(PS_SOLID, 2, RGB(34, 177, 76));
            SelectObject(hdc, hPen);

            int q1 = 5, p1 = 525;
            int q2 = 5, p2 = 505;
            do {
                MoveToEx(hdc, q1, p1, NULL);
                LineTo(hdc, q2, p2);

                q1 += 5;
                q2 += 5;
            } while (q1 <= 144);

            // Зонтик
            hPen = CreatePen(PS_SOLID, 2, RGB(235, 60, 60));
            SelectObject(hdc, hPen);

            int o1 = 800, r1 = 375;
            int o2 = 700, r2 = 425;

            do {
                MoveToEx(hdc, o1, r1, NULL);
                LineTo(hdc, o2, r2);
                
                o2 += 25;
            } while (o2 <= 901);

            MoveToEx(hdc, 700, 425, NULL);
            LineTo(hdc, 900, 425);
            hPen = CreatePen(PS_SOLID, 3, RGB(240, 146, 55));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 800, 425, NULL);
            LineTo(hdc, 800, 525);


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
