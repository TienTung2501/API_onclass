// DohoaCoSo.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "DohoaCoSo.h"

#define MAX_LOADSTRING 100

// Global Variables:
PAINTSTRUCT ps;
HDC hdc;
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DOHOACOSO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DOHOACOSO));

    MSG msg;

    // Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DOHOACOSO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DOHOACOSO);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //static POINT point[3] = { {400,100},{400,200},{200,200} };
    //static POINT point[4] = { {200,200},{100,300},{200,400},{300,300 } };
    static POINT sao[8] = { {200,200},{150,250},{100,300},{150,350},{200,400},{250,350},{300,300},{250,250}};
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
        hdc = BeginPaint(hWnd, &ps);
        
       /* int x = 200;
        int y = 50;
        
       while (x <= 400&&y<=200) {
            SetPixel(hdc, x, y, RGB(255, 0, 0));
            x++;
            y++;
        }
        x = 200;
        y = 350;

       while (x >=50&& y >= 200) {
           SetPixel(hdc, x, y, RGB(255, 0, 0));
           x--;;
           y--;
       }
       int z = 200;
       int t = 50;
        while (z >=50 && t <= 200) {
            SetPixel(hdc, z, t, RGB(255, 0, 0));
            z--;
            t++;

        }
        z = 350;
        t = 200;
        while (z >= 200 && t <= 400) {
            SetPixel(hdc, z, t, RGB(255, 0, 0));
            z--;
            t++;
        }*/
        //MoveToEx(hdc, 300, 300, NULL);
        //LineTo(hdc, 200, 300);
        //// vẽ đường gấp khúc:
        //// vẽ tam giác cân:
        //MoveToEx(hdc, 300, 300, NULL);
        //LineTo(hdc, 200, 300);

        //MoveToEx(hdc,200, 300,NULL);
        //LineTo(hdc, 250, 400),

        //MoveToEx(hdc, 300, 300, NULL);
        //LineTo(hdc, 250, 400);
       
        //Polyline(hdc, point, 3);
       // Polygon(hdc, point, 4);
        //Polygon(hdc,sao,8);
        //Rectangle(hdc, 50, 100, 500, 300); //Rectangle (hdc, xLeft, yTop, xRight, yBottom) ; xleft,ytop: toa do goc, xRight: chieu rong y bottom:chieu cao

        
        //Ellipse(hdc, 50, 100, 500, 300);
        //RoundRect(hdc, 50, 100, 500, 300,50,50);
        //RoundRect(hdc, 50, 100, 500, 300,250,170);
        Rectangle(hdc, 50, 100, 500, 300);
        MoveToEx(hdc, 50, 100, NULL);
        LineTo(hdc, 500, 300);
        MoveToEx(hdc, 500, 100, NULL);
        LineTo(hdc, 50, 300);
        Ellipse(hdc, 50, 100, 500, 300);
        RoundRect(hdc, 150,250, 450, 250, 20, 20);
        EndPaint(hWnd,&ps);
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

// Message handler for about box.
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
