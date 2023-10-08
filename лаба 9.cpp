// лаба 9.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "лаба 9.h"

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
    LoadStringW(hInstance, IDC_MY9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY9);
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
void StClausAuto(HDC hdc, int x, int y) {
    // верхний треугольник
    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x , 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    // средний треугольник
    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    // нижний треугольник
    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}

void drawTruck(HDC hdc, int x, int y) {

    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);

}

void drawTrucks1(HDC hdc) {

    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);

}

void drawTrucks2(HDC hdc) {

    int x = 0;

    do {
        drawTruck(hdc, x, 0);
        x += 110;
    } while (x < 660);
    
}

void drawTrucks3(HDC hdc) {

    int y = 0;

    do {
        drawTruck(hdc, 0, y);
        y += 70;
    } while (y < 420);

}

void drawTrucks4(HDC hdc) {

    int x = 0;
    int y = 0;

    do {
        drawTruck(hdc, x, y);
        x += 110;
        y += 70;
    } while (y < 420);

}

void logoToyota(HDC hdc, int x, int y) {

    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Ellipse(hdc, 10 + x, 10 + y, 100 + x, 60 + y);
    Ellipse(hdc, 25 + x, 10 + y, 85 + x, 30 + y);
    Ellipse(hdc, 45 + x, 10 + y, 65 + x, 60 + y);

}
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

            // ЗАДАЧА 1.1
            //StClausAuto(hdc, 0, 0);
            //StClausAuto(hdc, 200, 200);
            //StClausAuto(hdc, 100, 100);
            //StClausAuto(hdc, 0, 200);
            //StClausAuto(hdc, 200, 0);

            // ЗАДАЧА 1.2
            //int x = 0;
            // 
            //do {
            //    StClausAuto(hdc, x, 0);
            //    x += 50;
            //} while (x < 400);

            // ЗАДАЧА 1.3
            //int y = 0;
            // 
            //do {
            //    StClausAuto(hdc, 0, y);
            //    y += 90;
            //} while (y < 300);

            //ЗАДАЧА 1.4
            //int x = 0;
            //int y = 0;

            //do {
            //    StClausAuto(hdc, x, y);
            //    x += 40;
            //    y += 80;
            //} while (x < 160);

            // ЗАДАЧА 2.1
            //drawTruck(hdc, 100, 150);
            //drawTruck(hdc, 400, 400);
            
            // ЗАДАЧА 2.2
            //drawTrucks1(hdc);

            // ЗАДАЧА 2.3
            //drawTrucks2(hdc);

            // ЗАДАЧА 2.4
            //drawTrucks3(hdc);

            // ЗАДАЧА 2.5
            //drawTrucks4(hdc);

            // ЗАДАЧА 4
            //logoToyota(hdc, 30, 30);

            // ЗАДАЧА 5
            
            // 1
            //logoToyota(hdc, 10, 10);
            //logoToyota(hdc, 10, 310);
            //logoToyota(hdc, 310, 10);
            //logoToyota(hdc, 310, 310);
            //logoToyota(hdc, 160, 160);

            // 2
            //int x = 0;

            //do {
            //    logoToyota(hdc, x, 0);
            //    x += 110;
            //} while (x < 660);

            // 3
            //int y = 0;

            //do {
            //    logoToyota(hdc, 0, y);
            //    y += 70;
            //} while (y < 420);

            // 4
            int x = 0;
            int y = 0;

            do {
                logoToyota(hdc, x, y);
                x += 110;
                y += 70;
            } while (y < 420);

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
