#include <Windows.h>
#include "DirectX/dinput.h"
#pragma comment(lib,"dxguid.lib") 
#pragma comment(lib,"dinput8.lib")

class Mouse
{
private:
	HRESULT hr;		// for checking errors

	HINSTANCE hInstance;	// app hInstance - set by Create()
	HWND hWindow;			// set by Create()

	LPDIRECTINPUT8 lpDIObjectMouse;		// for DI device creating
	LPDIRECTINPUTDEVICE8 lpDIDeviceMouse;	// DI devise - Mouse

	DIMOUSESTATE mousestate;	// mouse state data
public:
	Mouse(HINSTANCE, HWND);		// Need app hInstance and hWindow
	bool Launch(void);		// launch while init
	bool Read(void);		// launch first in game cycle
	bool Click(int);		// get 1, 2 or 3 - number of mouse button
	int X(void);			// relative X displacing
	int Y(void);			// relative Y displacing
	~Mouse();
};