/*_________________________________________________________________________________________
	�����������: �������� ���� �������������
	��� ������ ���-091
	������������ ���� ��� �������� ���� � ��������� ��������� windows 
__________________________________________________________________________________________*/
#pragma once
#include <windows.h>
LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
class ApiWindow
{
	wchar_t *NameClass;
public:
	HWND hWnd;
	ApiWindow(){NameClass=L"Sample Window";} //����������� ��� ���������� ��������
	ApiWindow(wchar_t * name){NameClass=name;} //����������� � ������������� ������ �����
	void SetName(wchar_t* szName){NameClass=szName;} //���������� ����� ���
	void GetHandle(HWND * Handle){Handle=&hWnd;} //�������� ������������ ���� ���������� ����
    ATOM ClassRegistration(HINSTANCE hInstance); //���������������� �����
	bool Create(HINSTANCE hInstance, int); //������������� ����
	void Logic(); //������ WinApi
};
