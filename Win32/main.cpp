//
//  main.cpp
//  Processing
//
//  Created by 中国美术学院 陈天翼(Apollo Chen) on 1/28/19.
//  Copyright © 2019 Apollo Chen. All rights reserved.
//

#include <windows.h>
#include "lib/Processing.h"
#include <gl/wglext.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HINSTANCE, HWND *, HDC *, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

#define DRAW_TIMER 1
void CALLBACK TimerDrawProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);

extern void draw() __attribute__((weak_import));

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;

    /* enable OpenGL for the window */
    EnableOpenGL(hInstance, &hwnd, &hDC, &hRC);
    /* enable OpenGL functions */
    gl3wInit();
    ShowWindow(hwnd, nCmdShow);

    /* enable Processing context */
    openglAgent.PrepareOpenGL();

    /* run setup once */
    if (setup) {
        setup();
        SwapBuffers(hDC);
    }

    /* start draw loop */
    if (draw && $frameRate > 0) {
        SetTimer(hwnd, DRAW_TIMER, 1000 / $frameRate, TimerDrawProc);
    }

    /* program main loop */
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    KillTimer(hwnd, DRAW_TIMER);

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            $keyPressed = true;
            if (GetKeyState(VK_CONTROL) < 0 || GetKeyState(VK_MENU) < 0) {

            }
            else {
                switch (wParam) {
                case VK_UP:
                case VK_DOWN:
                case VK_HOME:
                case VK_INSERT:
                case VK_F1:
                case VK_F2:
                case VK_F3:
                case VK_F4:
                case VK_F5:
                case VK_F6:
                case VK_F7:
                case VK_F8:
                case VK_F9:
                case VK_F10:
                case VK_F11:
                case VK_F12:
                    $key = CODED;
                    $keyCode = wParam;
                    if (keyPressed)
                        keyPressed();
                    break;
                case VK_LEFT:
                    $key = CODED;
                    $keyCode = LEFT;
                    if (keyPressed)
                        keyPressed();
                    break;
                case VK_RIGHT:
                    $key = CODED;
                    $keyCode = RIGHT;
                    if (keyPressed)
                        keyPressed();
                    break;
                case VK_DELETE:
                    $key = CODED;
                    $keyCode = DELETE;
                    if (keyPressed)
                        keyPressed();
                    break;
                default:
                    break;
                }
            }
        }
        break;
        case WM_KEYUP:
            $keyPressed = false;
            if (keyReleased)
                keyReleased();
            if (keyTyped)
                keyTyped();
        break;
        case WM_CHAR:
            if (wParam == VK_BACK || wParam == VK_RETURN || wParam == VK_ESCAPE || wParam == VK_TAB)
            {
                $key = CODED;
                $keyCode = wParam;
            }
            else
            {
                $key = (TCHAR)wParam;
                $keyCode = 0;
            }
            if (keyPressed)
                keyPressed();
            break;
        case WM_MOUSEMOVE:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = (int)wParam;
            if ($mousePressed & MK_LBUTTON)
                if (mouseDragged)
                    mouseDragged();
            else if (mouseMoved)
                mouseMoved();
            break;
        case WM_MOUSEHOVER:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            break;
        case WM_MOUSELEAVE:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            break;
        case WM_MOUSEWHEEL:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            break;
        case WM_LBUTTONDOWN:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = (int)wParam;
            if (mousePressed)
                mousePressed();
            break;
        case WM_LBUTTONUP:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = 0;
            if (mouseReleased)
                mouseReleased();
            if (mouseClicked)
                mouseClicked();
            break;
        case WM_LBUTTONDBLCLK:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            break;
        case WM_MBUTTONDOWN:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = (int)wParam;
            if (mousePressed)
                mousePressed();
            break;
        case WM_MBUTTONUP:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = 0;
            if (mouseReleased)
                mouseReleased();
            if (mouseClicked)
                mouseClicked();
            break;
        case WM_MBUTTONDBLCLK:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            break;
        case WM_RBUTTONDOWN:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = (int)wParam;
            if (mousePressed)
                mousePressed();
            break;
        case WM_RBUTTONUP:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            $mousePressed = 0;
            if (mouseReleased)
                mouseReleased();
            if (mouseClicked)
                mouseClicked();
            break;
        case WM_RBUTTONDBLCLK:
            $mouseX = (int)LOWORD(lParam);
            $mouseY = (int)HIWORD(lParam);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

/*
 * Name: EnableOpenGL
 * Params: HINSTANCE hInstance, HWND * hwnd, HDC * hDC, HGLRC * hRC
 * Return: TRUE - success
 *         FALSE - fail
 * Description: Enable OpenGL
 */
void EnableOpenGL(HINSTANCE hInstance, HWND * hwnd, HDC * hDC, HGLRC * hRC)
{
    *hwnd = NULL;
    *hDC = NULL;
    *hRC = NULL;
    WNDCLASSEX wcex;
    /* register window class */
	ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "Sketch";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;

    if (!RegisterClassEx(&wcex))
        return;

	DWORD style = WS_CAPTION | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;//WS_OVERLAPPEDWINDOW;//

	// create temporary window
	HWND helpWND = CreateWindowEx(0,
                          "Sketch",
                          "cProcessing Sketch",
                          style,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          256,
                          256,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

	HDC helpDC = GetDC(helpWND);	// Device Context

	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 24;

	const int helpPFDID = ChoosePixelFormat(helpDC, &pfd);
	if (helpPFDID == 0) {
		printf("ChoosePixelFormat() failed.");
		return;
	}

	if (SetPixelFormat(helpDC, helpPFDID, &pfd) == false) {
		printf("SetPixelFormat() failed.");
		return;
	}

	HGLRC helpRC = wglCreateContext(helpDC);	// Rendering Contex

	if (helpRC == 0) {
		printf("wglCreateContext() failed.");
		return;
	}

	if (wglMakeCurrent(helpDC, helpRC) == false) {
		printf("wglMakeCurrent() failed.");
		return;
	}

	// get pointers to functions (or init opengl loader here)
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
	wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
	if (wglChoosePixelFormatARB == nullptr) {
		printf("wglGetProcAddress() failed.");
		return;
	}

	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
	wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
	if (wglCreateContextAttribsARB == nullptr) {
		printf("wglGetProcAddress() failed.");
		return;
	}

	const int pixelAttribs[] = {
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_ALPHA_BITS_ARB, 8,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		0
	};

	/* remove help context */
	DisableOpenGL(helpWND, helpDC, helpRC);
	DestroyWindow(helpWND);

    /* create main window */
    *hwnd = CreateWindowEx(0,
                          "Sketch",
                          "cProcessing Sketch",
                          style,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          256,
                          256,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    *hDC = GetDC(*hwnd);

	int pixelFormatID;
    UINT numFormats;
	const bool status = wglChoosePixelFormatARB(*hDC, pixelAttribs, NULL, 1, &pixelFormatID, &numFormats);

	if (status == false || numFormats == 0) {
		printf("wglChoosePixelFormatARB() failed.");
		return;
	}

	DescribePixelFormat(*hDC, pixelFormatID, sizeof(pfd), &pfd);
	SetPixelFormat(*hDC, pixelFormatID, &pfd);

	const int major_min = 3, minor_min = 3;
	const int contextAttribs[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, major_min,
		WGL_CONTEXT_MINOR_VERSION_ARB, minor_min,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
//		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
		0
	};


	*hRC = wglCreateContextAttribsARB(*hDC, 0, contextAttribs);
	if (*hRC == NULL) {
		printf("wglCreateContextAttribsARB() failed.");
		return;
	}


	if (!wglMakeCurrent(*hDC, *hRC)) {
		printf("wglMakeCurrent() failed.");
		return;
	}
}

/*
 * Name: DisableOpenGL
 * Params:
 * Description: Disable OpenGL while exiting
 */
void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

/*
 * Name: TimerDrawProc
 * Params:
 * Description: Draw frame loop
 */

void CALLBACK TimerDrawProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    KillTimer(hwnd, DRAW_TIMER);
    POINT point;
    GetCursorPos(&point);
    ScreenToClient(hwnd, &point);
    $mouseX = point.x;
    $mouseY = point.y;
    if ($loop) {
        resetMatrix();
        draw();
        SwapBuffers(GetDC(hwnd));
    }
    $pmouseX = $mouseX;
    $pmouseY = $mouseY;
    if ($frameRate > 0)
        SetTimer(hwnd, DRAW_TIMER, 1000 / $frameRate, TimerDrawProc);
}

/*
 * Name: resizeWindow
 * Params: width - new window width
 *         height - new window height
 * Description: Resize window
 */
void resizeWindow(int width, int height)
{
    HWND hwnd = GetActiveWindow();
    RECT rect = { 0, 0,  0, 0};
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, width + 6, height + 30, true);
}
