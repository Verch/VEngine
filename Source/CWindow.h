/*_________________________________________________________________________________________
	Разработчик: Соловьев Олег Александрович
	БРУ группа ПРИ-091
	Заголовочный файл для создания окна и обработки сообщений windows 
__________________________________________________________________________________________*/
#pragma once
#include <windows.h>
LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
class ApiWindow
{
	wchar_t *NameClass;
public:
	HWND hWnd;
	ApiWindow(){NameClass=L"Sample Window";} //Конструктор без введенного значение
	ApiWindow(wchar_t * name){NameClass=name;} //Конструктор с установлением нового имени
	void SetName(wchar_t* szName){NameClass=szName;} //Установить новое имя
	void GetHandle(HWND * Handle){Handle=&hWnd;} //Получить заголовочный файл созданного окна
    ATOM ClassRegistration(HINSTANCE hInstance); //Зарегистрировать класс
	bool Create(HINSTANCE hInstance, int); //Инициализация окна
	void Logic(); //Логика WinApi
};
