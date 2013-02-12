#include "CWindow.h"
// ����� ������������� ���� [
bool ApiWindow::Create(HINSTANCE hInstance, int)
{
	this->hWnd = CreateWindowExW( NULL, 
					  L"wndClass", 
					  NameClass, 
					  WS_EX_OVERLAPPEDWINDOW | WS_VISIBLE,
					  200,100,//CW_USEDEFAULT,CW_USEDEFAULT,
					  800, 600, //[GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN)]
					  NULL, NULL, 
					  hInstance, NULL);
	if(!hWnd){return FALSE;}
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	return TRUE;}

// ����������� ������ ���� [
ATOM ApiWindow::ClassRegistration(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.lpszClassName=L"wndClass"; 
	wc.lpfnWndProc=wndProc;      
	wc.lpszMenuName=NULL;      
	wc.cbSize=sizeof(wc);    
	wc.cbClsExtra=0;        
	wc.cbWndExtra=0;        
	wc.hbrBackground=CreateSolidBrush(RGB(0,0,0)); 
	wc.hCursor=LoadCursor(NULL,IDC_CROSS); 
	wc.hIcon=LoadCursor(hInstance,IDI_APPLICATION); 
	wc.hIconSm=LoadIcon(hInstance,IDC_CROSS); 
return RegisterClassEx(&wc);}

// ������� ��������� �������� ��������� ����� [
LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}
// ������� ������ WinApi
void ApiWindow::Logic()
{
	if(GetAsyncKeyState(VK_ESCAPE))
	{   
		PostMessage(hWnd,WM_QUIT,0,0);
	}
/* [ vbloov- ]
if(GetAsyncKeyState(VK_ESCAPE))
	{   
		int result=MessageBox(hWnd,L"Do you want to close the application?",L"Exit Game",MB_YESNO);
		if(result==6)PostMessage(hWnd,WM_QUIT,0,0);
	}
*/ 
}
