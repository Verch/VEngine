#include "main.h"

// Entry point
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	boost::shared_ptr<ApiWindow> windowMain(new ApiWindow);
	windowMain->SetName(L"VEngine");
	if (!windowMain->ClassRegistration(hInstance)) 
	{
		MessageBox(NULL,L"Ошибка установки параметров и получения класса окна",L"Ошибка Windows",MB_OK);
		return 0;
	}

	if (!windowMain->Create(hInstance,nCmdShow))
	{
		MessageBox(NULL,L"Ошибка завершения создания класса окна и получения его дискриптора",L"Ошибка Windows",MB_OK);
		return 0;
	}

	boost::shared_ptr<EngineManager> engine(new EngineManager);


	MSG msg;
	ZeroMemory(&msg,sizeof(msg));
	while(msg.message!=WM_QUIT)
	{ 
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg); 
		}
		windowMain->Logic(); // [Esc] to exit
	}
}