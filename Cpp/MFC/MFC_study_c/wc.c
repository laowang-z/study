#include <windows.h> 
//底层实现窗口的头文件
#include <stdio.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		// 所有以Window结尾的不会进入消息队列，而是由操作系统直接执行
		DestroyWindow(hwnd); //会发送另一个消息：WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: // 鼠标左键按下
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		char aaa[1024];
		wsprintf(aaa, TEXT("xPos = %d, yPos = %d"), xPos, yPos);
		//char sss[25];
		//sprintf_s(sss, sizeof(sss), "xPos = %d, yPos = %d", xPos, yPos);
		//TCHAR aaa[50];
		//#ifdef UNICODE
		//MultiByteToWideChar(CP_ACP, 0, sss, -1, aaa, 50);
		//#else
		//	strcpy(aaa, sss);
		//#endif
		MessageBox(hwnd, aaa, TEXT("鼠标左键"), MB_OK);
		break;
	}
	case WM_KEYDOWN: // 键盘按下
	{
		MessageBox(hwnd, TEXT("键盘"), TEXT("键盘左键"), MB_OK);
		break;
	}
	case WM_PAINT: // 绘图
	{
		PAINTSTRUCT ps; // 绘图结构体
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("Image"), sizeof("Image"));
		EndPaint(hwnd, &ps);
		break;
	}

	}
	// 返回值用默认处理方式
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


//程序入口函数

// WINAPI代表__stdcall参数的传递顺序：从右到左依次入栈，并在函数返回前清空堆栈
int WINAPI WinMain(
	HINSTANCE hInstance, //应用程序实例句柄
	HINSTANCE hPrevInstance, //上一个应用程序句柄，在win32环境下一般为NULL，不起作用
	LPSTR lpCmdLine, //相当于 char * argv[]为命令行参数
	int nShowCmd) //显示命令 最大化、最小化、正常……
{
	//1. 设计窗口
	//2. 注册窗口
	//3. 创建窗口
	//4. 显示和更新
	//5. 通过循环取消息
	//6. 处理消息（窗口过程）

	//设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0; //类的额外内存
	wc.cbWndExtra = 0; //窗口额外的内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //设置背景，其中WHITE_BRUSH表示白色刷子，(HBRUSH)为强制类型转换
	wc.hCursor = LoadCursor(NULL, IDC_HAND); //设置光标，如果第一个参数为NULL，代表使用系统提供的光标，IDC_HAND为手型光标
	wc.hIcon = LoadIcon(NULL, IDI_ERROR); //设置图标，
	wc.hInstance = hInstance; //应用程序实例句柄，传入WinMain中的形参即可
	wc.lpfnWndProc = WindowProc; //回调函数，窗口过程
	wc.lpszClassName = TEXT("WIN"); //指定窗口类名
	wc.lpszMenuName = NULL; //菜单名称
	wc.style = 0; //显示风格，0为默认

	// 注册窗口
	RegisterClass(&wc);

	// 创建窗口
	/*lpClassName, 类名
	lpWindowName, 标题名
	dwStyle, 风格
	x, 显示坐标 默认值CW_USEDEFAULT
	y,
	nWidth, 宽
	nHeight, 高
	hWndParent, 父窗口 没有为NULL
	hMenu, 菜单 没有为NULL
	hInstance, 实例句柄
	lpParam 附加值
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("WINDOWS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	// 显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL); // 前一个参数为创建的窗口，后一个为显示模式

	UpdateWindow(hwnd);

	// 循环获取消息

	/*
	HWND        hwnd; 主窗口句柄
	UINT        message; 具体消息名称
	WPARAM      wParam; 附加消息 键盘消息
	LPARAM      lParam; 附加消息 鼠标消息
	DWORD       time; 消息产生时间
	POINT       pt; 附加消息 鼠标消息(x, y)坐标
	*/
	MSG msg;
	while (1)
	{
		/*
		_Out_ LPMSG lpMsg, 消息
		_In_opt_ HWND hWnd, 捕获窗口 NULL表示捕获所有窗口
		_In_ UINT wMsgFilterMin, 最小的过滤消息，一般为0
		_In_ UINT wMsgFilterMax); 最大的过滤消息，与前一个同为0时捕获所有消息
		*/
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		TranslateMessage(&msg); // 翻译消息

		DispatchMessage(&msg); // 分发消息
	}

	// 窗口过程
	/*
	LRESULT Wndproc(
		HWND unnamedParam1, 消息所属窗口句柄
		UINT unnamedParam2, 具体消息名称 WM_XXXX消息名
		WPARAM unnamedParam3, 键盘附加消息
		LPARAM unnamedParam4 鼠标附加消息
	)
	{
		...
	}
	*/



	return 0;
}



