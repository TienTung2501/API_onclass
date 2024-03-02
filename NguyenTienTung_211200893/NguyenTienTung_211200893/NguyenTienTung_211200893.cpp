// NguyenTienTung_211200893.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "NguyenTienTung_211200893.h"
#include <cmath>


#define MAX_LOADSTRING 100

// Global Variables:
static COLORREF selectedColorVien = RGB(0, 0, 0); // Màu mặc định là đen
static COLORREF selectedColorNen = RGB(0, 0, 0);
static bool isRect = false;
static bool isLine = false;
static bool isRed = false;
static bool isGreen = false;
static bool isSao = false;
static bool isElipse = false;
HINSTANCE hInst;                                // current instance thực thể chương trình ứng dụng hiện tại, preInst là thực thể chương trình trước đó
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text // thanh tiêu đề tên của cửa sổ
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
    UNREFERENCED_PARAMETER(hPrevInstance);// không tham chiếu đến thực thể chương trình ứng dụng hiện tại
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);// load tên
    LoadStringW(hInstance, IDC_NGUYENTIENTUNG211200893, szWindowClass, MAX_LOADSTRING);// load tên
    MyRegisterClass(hInstance);// đăng kí lớp thực thể

   
    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NGUYENTIENTUNG211200893));

    MSG msg;

    // Main message loop:// vòng lặp nhận thông điệp chương trình
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCEW(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_NGUYENTIENTUNG211200893);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

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
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)// khởi tạo cửa sổ
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd1 = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,// HWND là một cửa sổ
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);  
 //  HWND hWnd2 = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,// HWND là một cửa sổ
    //  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(HINH));
   SetMenu(hWnd1,hMenu);
   

   if (!hWnd1)
   {
      return FALSE;
   }
   // nCmdShow tham số cho biết vị chí và trạng thái chạy trương trình lấp đầy màn hình hay gì
   ShowWindow(hWnd1, nCmdShow);
 //  ShowWindow(hWnd2, nCmdShow);
   UpdateWindow(hWnd1);
 //  UpdateWindow(hWnd2);

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
void DrawTriangle(HDC hdc, POINT startPoint, POINT endPoint) {
    POINT pt[3];
    pt[0] = startPoint;
    pt[1] = { startPoint.x, endPoint.y };
    pt[2] = endPoint;

    Polygon(hdc, pt, 3);
}
void DrawLine(HDC hdc, POINT startPoint, POINT endPoint) {
    MoveToEx(hdc, startPoint.x, startPoint.y, NULL);
    LineTo(hdc, endPoint.x, endPoint.y);

}
void DrawStar(HDC hdc, POINT startPoint, POINT endPoint) {
    int x1 = startPoint.x;
    int x2 = endPoint.x;
    int y1 = startPoint.y;
    int y2 = endPoint.y;
    POINT sao4Canh[8];
    sao4Canh[0] = { (x1 + x2) / 2, y1 };
    sao4Canh[1] = { (5 * x1 + 3 * x2) / 8,(5 * y1 + 3 * y2) / 8 };
    sao4Canh[2] = { x1,(y1 + y2) / 2 };
    sao4Canh[3] = { (5 * x1 + 3 * x2) / 8 , (3 * y1 + 5 * y2) / 8 };
    sao4Canh[4] = { (x1 + x2) / 2, y2 };
    sao4Canh[5] = { (3 * x1 + 5 * x2) / 8, (3 * y1 + 5 * y2) / 8 };
    sao4Canh[6] = { x2,(y1 + y2) / 2 };
    sao4Canh[7] = { (3 * x1 + 5 * x2) / 8,(5 * y1 + 3 * y2) / 8 };

    Polygon(hdc, sao4Canh, 8);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)// thủ tục
{
    static POINT startPoint;
    //static bool isDrawing = false;
    
    static HPEN hPen;
    static HBRUSH hBrush;
    static int s = 0, m = 2;
    static TCHAR text[100];
    HDC hdc;
    switch (message)
    {
    
    case WM_TIMER:
        if (s == 0 && m == 0) {
            MessageBox(NULL, TEXT("Đã hết giờ"), TEXT("THÔNG BÁO"), MB_OK || MB_ICONINFORMATION);
            KillTimer(hWnd, 8888);
        }
        else if (s > 0 && s <= 59) {
            s--;
        }
        else if (s == 0) {
            m--;
            s = 59;
        }
        wsprintf(text, L"Thời gian:%d: %d", m, s);
        hdc = GetDC(hWnd);
        TextOut(hdc, 50, 50, text, 100);
        ReleaseDC(hWnd, hdc);
        break;
    case WM_CREATE:
        SetTimer(hWnd, 8888, 1000, NULL);
        break;
    case WM_LBUTTONDOWN:
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
//        isDrawing = true;
        break;

    case WM_LBUTTONUP:
    {
        HDC hdc = GetDC(hWnd);
        POINT currentPoint;
        currentPoint.x = LOWORD(lParam);
        currentPoint.y = HIWORD(lParam);
        hPen = CreatePen(PS_SOLID, 1, selectedColorVien);
        hBrush = CreateSolidBrush(selectedColorNen);
        SelectObject(hdc, hPen);
        SelectObject(hdc, hBrush);
        if (isRect) {
            DrawTriangle(hdc, startPoint, currentPoint);
        }
        else if (isLine) {
            DrawLine(hdc, startPoint, currentPoint);
        }
        else if (isElipse) {
            Ellipse(hdc, startPoint.x, startPoint.y, currentPoint.x, currentPoint.y);

        }
        else if (isSao) {
            DrawStar(hdc, startPoint, currentPoint);
        }

        ReleaseDC(hWnd, hdc);
        break;
    }


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CLOSE:
        if (MessageBox(hWnd, L"Bạn có muốn thoát không?", L"Xác nhận", MB_YESNO | MB_ICONQUESTION) == IDYES) {
            DestroyWindow(hWnd);
        }
        break;
    case WM_RBUTTONDOWN:
        static HMENU hMenu;
        POINT point;
        hMenu = LoadMenu(hInst, MAKEINTRESOURCE(MENU_POPUP)); //Hoặc sử dụng GetMenu()
        hMenu = GetSubMenu(hMenu, 0);
        point.x = LOWORD(lParam);
        point.y = HIWORD(lParam);
        ClientToScreen(hWnd, &point);
        TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, point.x, point.y, 0, hWnd, NULL);
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);

        // Parse the menu selections:
        switch (wmId)
        {
        case VIEN_DO:
            selectedColorVien = RGB(255, 0, 0); // Màu đỏ
            break;
        case VIEN_XANH:
            selectedColorVien = RGB(0, 255, 0); // Màu xanh
            break;
        case NEN_DO:
            selectedColorNen = RGB(255, 0, 0); // Màu đỏ
            break;
        case NEN_XANH:
            selectedColorNen = RGB(0, 255, 0); // Màu xanh
            break;
        case TAMGIAC:
            isElipse = false;
            isSao = false;
            isLine = false;
            isRect = true;
            break;
        case DUONGTHANG:
            isElipse = false;
            isRect = false;
            isSao = false;
            isLine = true;
            break;
        case HINHSAO:
            isElipse = false;
            isRect = false;
            isLine = false;
            isSao = true;
            break;
        case ELIP:
            isRect = false;
            isLine = false;
            isSao = false;
            isElipse = true;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }

        // Gọi lại hàm vẽ lại cửa sổ để áp dụng màu mới
        //InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Tạo một bút với màu được chọn

        EndPaint(hWnd, &ps);
    }
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
