#include "main.h"

// Entry point
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	boost::shared_ptr<ApiWindow> windowMain(new ApiWindow);
	windowMain->SetName(L"VEngine");
	windowMain->ClassRegistration(hInstance);
	windowMain->Create(hInstance,nCmdShow);

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