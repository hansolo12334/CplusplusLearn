#include<Windows.h>


#include<iostream>





/**
 * 处理窗口过程
 * HWND hWnd 消息所属的窗口句柄
 * UINT uMsg 具体的消息名称
 * WPARAM wParam 键盘附加消息
 * LPARAM lParam 鼠标附加消息
*/

LRESULT CALLBACK WindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
)
{
    //根据不同消息做不同的处理
    switch (uMsg) {
        //关闭窗口 发送另一个消息WM_DESTROY
        case WM_CLOSE:
        {
            DestroyWindow(hWnd); //所有xxxWindow为结尾的方法都不会进入消息队列而会直接执行
            break;
        }

        //关闭窗口退出进程
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }

        //鼠标左键按下
        case WM_LBUTTONDOWN:
        {
            int xPos = LOWORD(lParam);
            int yPos = HIWORD(lParam);
            wchar_t buf[1024];
            wsprintfW(buf, L"X = %d Y = %d", xPos, yPos); //todo 从“char [1024]”到“LPCWSTR”的类型不兼容

            MessageBoxW(hWnd, buf, L"TITLE", MB_OK);
            break;
        }
        //键盘按下
        case WM_KEYDOWN:
        {
            MessageBox(hWnd, TEXT("KEYDOWN"), TEXT("TITLE"), MB_OK);
            break;
        }

        //绘图
        case WM_PRINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 100, 100, TEXT("PRINT"), static_cast<int>(strlen("PRINT")));
            EndPaint(hWnd, &ps);
            break;
        }
        // default:
        // {
        //     //返回值使用默认处理方式
        //     return DefWindowProc(hWnd, uMsg, wParam, lParam);
        // }

    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);

}


int WINAPI WinMain( HINSTANCE hInstance,
                    HINSTANCE hPreInstance,
                    LPSTR lpCmdLine,
                    int nShowCmd
                    )
{
  //1.设计窗口
  //2.注册窗口
  //3.创建窗口
  //4.显示更新
  //5.通过循环获取消息
  //6.处理消息即窗口过程

  WNDCLASS wc;//Windows类


  wc.cbClsExtra = 0;//类的额外内存
  wc.cbWndExtra = 0;//窗口额外内存
  wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//设置背景

  wc.hCursor = LoadCursor(NULL, IDI_HAND);//设置光标,参数1为NULL为系统提供的光标

  wc.hIcon = LoadIcon(NULL, IDI_INFORMATION);//设置图标

  wc.hInstance = hInstance; //应用程序实例句柄，传入实例句柄

  wc.lpfnWndProc = WindowProc;//窗口过程，即回调函数

  wc.lpszClassName = TEXT("WIN"); //窗口类名

  wc.lpszMenuName = NULL; //窗口菜单名称

  wc.style = 0;//显示风格 0默认风

  //注册窗口
  RegisterClass(&wc);


    //创建窗口
    // lpClassName 窗口类名
    // lpWindowName 窗口标题名称
    // dwStyle 窗口风格 混合风格
    // x X坐标 默认值 CW_USERDEFAULT
    // y Y坐标 默认值 CW_USERDEFAULT
    // nWidth
    // nHeight 默认值 CW_USERDEFAULT
    // hWndParent 父窗口，顶层方式弹出为NULL
    // hMenu 窗口菜单
    // hInstance 实例句柄
    // lpParam 附加值

  HWND hwnd = CreateWindow(
        wc.lpszClassName,
        TEXT("WINDOWS"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
      );

  MSG msg;
   //显示更新
  ShowWindow(hwnd, SW_SHOWNORMAL);

  UpdateWindow(hwnd);

   //通过循环获取消息
    /*
        每个消息都是一个结构体
        HWND hwnd; 主窗口句柄
        UINT message; 消息名称
        WPARAM wParam; 附件消息 通常为键盘消息
        LPARAM lParam; 附加消息 通常为鼠标左右键消息
        DWORD time; 消息产生时间
        POINT pt; 附加消息 鼠标坐标点消息
    */

  std::cout << '0' << '\n';
  while(GetMessage(&msg,NULL,0,0)==TRUE)
  {
  /*
    捕获消息 GetMessage()
    _Out_ LPMSG lpMsg;//消息地hi
    _In_opt_ HWND hWnd;//捕获窗口 NULL为捕获所有窗口
    _In_ UNIT wMsgFilterMin;//最小的过滤消息 0表示捕获所有消息
    _In_ UINT wMsgFilterMax;//最大的过滤消息 0表示捕获所有消息
    */
    //if (GetMessage(&msg, NULL, 0, 0) == FALSE) {
    //  break;//若关闭窗口则退出死循环
    //}
    // 翻译消息
    std::cout << '1' << '\n';

    TranslateMessage(&msg); //例如针对键盘组合快捷键需翻译
    //分发消息
    DispatchMessage(&msg);

  }
  return 0;

}
