// lab7 while.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab7 while.h"

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
    LoadStringW(hInstance, IDC_LAB7WHILE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB7WHILE));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB7WHILE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB7WHILE);
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

            MoveToEx(hdc, 100, 100, NULL);
            hPen = CreatePen(PS_SOLID, 4, RGB(140, 70, 70));
            SelectObject(hdc, hPen);
            // Дом
            LineTo(hdc, 175, 50);
            LineTo(hdc, 250, 100);
            LineTo(hdc, 100, 100);
            LineTo(hdc, 100, 225);
            LineTo(hdc, 250, 225);
            LineTo(hdc, 250, 100);

            MoveToEx(hdc, 150, 125, NULL);
            LineTo(hdc, 200, 125);
            LineTo(hdc, 200, 175);
            LineTo(hdc, 150, 175);
            LineTo(hdc, 150, 125);

            MoveToEx(hdc, 175, 125, NULL);
            LineTo(hdc, 175, 175);

            MoveToEx(hdc, 175, 150, NULL);
            LineTo(hdc, 200, 150);

            // ёлка
            hPen = CreatePen(PS_SOLID, 2, RGB(40, 190, 40));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 300, 225, NULL);
            LineTo(hdc, 450, 225);
            LineTo(hdc, 375, 175);
            LineTo(hdc, 300, 225);

            MoveToEx(hdc, 325, 175, NULL);
            LineTo(hdc, 425, 175);
            LineTo(hdc, 375, 125);
            LineTo(hdc, 325, 175);

            MoveToEx(hdc, 400, 125, NULL);
            LineTo(hdc, 350, 125);
            LineTo(hdc, 375, 100);
            LineTo(hdc, 400, 125);

            // дерево
            MoveToEx(hdc, 50, 225, NULL);
            hPen = CreatePen(PS_SOLID, 3, RGB(175, 50, 0));
            SelectObject(hdc, hPen);
            LineTo(hdc, 50, 50);
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 200, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 50, 200, NULL);
            LineTo(hdc, 75, 150);
            MoveToEx(hdc, 50, 200, NULL);
            LineTo(hdc, 25, 175);
            MoveToEx(hdc, 50, 175, NULL);
            LineTo(hdc, 25, 125);
            MoveToEx(hdc, 50, 150, NULL);
            LineTo(hdc, 75, 125);
            MoveToEx(hdc, 50, 125, NULL);
            LineTo(hdc, 25, 50);
            MoveToEx(hdc, 50, 125, NULL);
            LineTo(hdc, 75, 75);
            MoveToEx(hdc, 50, 75, NULL);
            LineTo(hdc, 75, 50);
            //kyst 1
            int x1 = 150;
            int y1 = 375;
            int x2 = 50;
            int y2 = 300;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x2 += 10;
            } while (x2 <= 250);
            //kyst 2
            x1 = 425;
            y1 = 400;
            x2 = 350;
            y2 = 400;
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x2 += 5;
                y2 -= 10;
            } while (x2 <= 425);
            //x2 += 5;
            y2 += 20;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x2 += 5;
                y2 += 10;
            } while (x2 <= 500);

            //забор
            x1 = 150;
            y1 = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);

                LineTo(hdc, x1, y1 + 50);
                x1 += 5;
            } while (x1 <= 450);

            hPen = CreatePen(PS_SOLID, 2, RGB(255, 100, 30));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 50, 300, NULL);
            int x = 50;
            int y = 300;
            x2 = 50;
            y2 = 300;
            int i = 1;
            do {
                x += 25;
                y -= 25;
                LineTo(hdc, x, y);
                x += 25;
                y += 25;
                LineTo(hdc, x, y);
                i++;
            } while (i <= 6);
            MoveToEx(hdc, 50, 300, NULL);
            i = 1;
            do {
                y2 += 75;
                LineTo(hdc, x2, y2);
                x2 += 50;
                y2 -= 75;
                MoveToEx(hdc, x2, y2, NULL);
                i++;
            } while (i <= 7);
            MoveToEx(hdc, 350, 375, NULL);
            LineTo(hdc, 50, 375);

            hPen = CreatePen(PS_SOLID, 2, RGB(0, 20, 20));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 650, 50, NULL);
            LineTo(hdc, 650, 300);
            x1 = 550;
            y1 = 125;
            x2 = 550;
            y2 = 125;
            do {
                MoveToEx(hdc, 650, 50, NULL);
                LineTo(hdc, x2, y2);
                x2 += 10;
                if (x2 <= 650) {
                    y2 += 1;
                }
                else {
                    y2 -= 1;
                }
                if (x2 <= 750) {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);
                }
                
                x1 = x2;
                y1 = y2;
            } while (x2 <= 750);

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
