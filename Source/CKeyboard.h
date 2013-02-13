#include <Windows.h>
#include "DirectX/dinput.h"
#pragma comment(lib,"dxguid.lib") 
#pragma comment(lib,"dinput8.lib")

#define KEYSTATEBYTES 256

class Keyboard
{
private:
	HRESULT hr;		// for checking errors

	HINSTANCE hInstance;	// app hInstance - set by Create()
	HWND hWindow;			// set by Create()

	LPDIRECTINPUT8 lpDIObjectKeyboard;		// for DI device creating
	LPDIRECTINPUTDEVICE8 lpDIDeviceKeyboard;	// DI devise - Keyboard

	UCHAR keystate[KEYSTATEBYTES];	// keyboard data
public:
	Keyboard(HINSTANCE, HWND);		// Need app hInstance and hWindow
	bool Launch(void);		// launch while init
	bool Read(void);		// launch first in game cycle
	bool KeyDown(UCHAR);	// get DIK_SPACE, DIK_LEFT e.t.c
	~Keyboard();
};