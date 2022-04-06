#include <windows.h> 
//�ײ�ʵ�ִ��ڵ�ͷ�ļ�
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
		// ������Window��β�Ĳ��������Ϣ���У������ɲ���ϵͳֱ��ִ��
		DestroyWindow(hwnd); //�ᷢ����һ����Ϣ��WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: // ����������
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
		MessageBox(hwnd, aaa, TEXT("������"), MB_OK);
		break;
	}
	case WM_KEYDOWN: // ���̰���
	{
		MessageBox(hwnd, TEXT("����"), TEXT("�������"), MB_OK);
		break;
	}
	case WM_PAINT: // ��ͼ
	{
		PAINTSTRUCT ps; // ��ͼ�ṹ��
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("Image"), sizeof("Image"));
		EndPaint(hwnd, &ps);
		break;
	}

	}
	// ����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


//������ں���

// WINAPI����__stdcall�����Ĵ���˳�򣺴��ҵ���������ջ�����ں�������ǰ��ն�ջ
int WINAPI WinMain(
	HINSTANCE hInstance, //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, //��һ��Ӧ�ó���������win32������һ��ΪNULL����������
	LPSTR lpCmdLine, //�൱�� char * argv[]Ϊ�����в���
	int nShowCmd) //��ʾ���� ��󻯡���С������������
{
	//1. ��ƴ���
	//2. ע�ᴰ��
	//3. ��������
	//4. ��ʾ�͸���
	//5. ͨ��ѭ��ȡ��Ϣ
	//6. ������Ϣ�����ڹ��̣�

	//��ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0; //��Ķ����ڴ�
	wc.cbWndExtra = 0; //���ڶ�����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ñ���������WHITE_BRUSH��ʾ��ɫˢ�ӣ�(HBRUSH)Ϊǿ������ת��
	wc.hCursor = LoadCursor(NULL, IDC_HAND); //���ù�꣬�����һ������ΪNULL������ʹ��ϵͳ�ṩ�Ĺ�꣬IDC_HANDΪ���͹��
	wc.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ�꣬
	wc.hInstance = hInstance; //Ӧ�ó���ʵ�����������WinMain�е��βμ���
	wc.lpfnWndProc = WindowProc; //�ص����������ڹ���
	wc.lpszClassName = TEXT("WIN"); //ָ����������
	wc.lpszMenuName = NULL; //�˵�����
	wc.style = 0; //��ʾ���0ΪĬ��

	// ע�ᴰ��
	RegisterClass(&wc);

	// ��������
	/*lpClassName, ����
	lpWindowName, ������
	dwStyle, ���
	x, ��ʾ���� Ĭ��ֵCW_USEDEFAULT
	y,
	nWidth, ��
	nHeight, ��
	hWndParent, ������ û��ΪNULL
	hMenu, �˵� û��ΪNULL
	hInstance, ʵ�����
	lpParam ����ֵ
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("WINDOWS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	// ��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL); // ǰһ������Ϊ�����Ĵ��ڣ���һ��Ϊ��ʾģʽ

	UpdateWindow(hwnd);

	// ѭ����ȡ��Ϣ

	/*
	HWND        hwnd; �����ھ��
	UINT        message; ������Ϣ����
	WPARAM      wParam; ������Ϣ ������Ϣ
	LPARAM      lParam; ������Ϣ �����Ϣ
	DWORD       time; ��Ϣ����ʱ��
	POINT       pt; ������Ϣ �����Ϣ(x, y)����
	*/
	MSG msg;
	while (1)
	{
		/*
		_Out_ LPMSG lpMsg, ��Ϣ
		_In_opt_ HWND hWnd, ���񴰿� NULL��ʾ�������д���
		_In_ UINT wMsgFilterMin, ��С�Ĺ�����Ϣ��һ��Ϊ0
		_In_ UINT wMsgFilterMax); ���Ĺ�����Ϣ����ǰһ��ͬΪ0ʱ����������Ϣ
		*/
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		TranslateMessage(&msg); // ������Ϣ

		DispatchMessage(&msg); // �ַ���Ϣ
	}

	// ���ڹ���
	/*
	LRESULT Wndproc(
		HWND unnamedParam1, ��Ϣ�������ھ��
		UINT unnamedParam2, ������Ϣ���� WM_XXXX��Ϣ��
		WPARAM unnamedParam3, ���̸�����Ϣ
		LPARAM unnamedParam4 ��긽����Ϣ
	)
	{
		...
	}
	*/



	return 0;
}



