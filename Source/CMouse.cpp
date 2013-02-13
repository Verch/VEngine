#include <CMouse.h>

Mouse::Mouse(HINSTANCE hInst, HWND hWnd)
{
	this->hInstance = hInst;
	this->hWindow = hWnd;
}

bool Mouse::Launch()
{
	/* Create Direct Input Object */
	hr = DirectInput8Create(hInstance,	// instance of creating app
		DIRECTINPUT_VERSION,	// vers of DI that app requires
		IID_IDirectInput8,		// indefiner of the required interface
		reinterpret_cast<void **>(&lpDIObjectMouse),	// pointer to soon-to-be-created DI object
		NULL);						// pUnkOuter
	if (FAILED(hr))	return false;

	/* Create Direct Input Device */
	hr = lpDIObjectMouse->CreateDevice(GUID_SysMouse,		// keyboard, mouse...
		&lpDIDeviceMouse,	// pointer to soon-to-be-created DI device
		NULL);		// pUnkOuter
	if (FAILED(hr)) return false;

	/* Set Direct Input Data Format */
	hr = lpDIDeviceMouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(hr)) return false;

	/* Set input control  */
	hr = lpDIDeviceMouse->SetCooperativeLevel(hWindow,
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (FAILED(hr)) return false;

	/* Get keyboard control to app  */
	hr = lpDIDeviceMouse->Acquire();
	if (FAILED(hr)) return false;

	return true;	
}

bool Mouse::Read()
{
	hr = lpDIDeviceMouse->GetDeviceState(sizeof(DIMOUSESTATE),
		static_cast<LPVOID>(&mousestate));
	if (FAILED(hr)) return false;

	return true;
}

bool Mouse::Click(int button)
{
	if (mousestate.rgbButtons[button-1]&0x80) return true;
	else return false;
}

int Mouse::X()
{
	return static_cast<int>(mousestate.lX);
}

int Mouse::Y()
{
	return static_cast<int>(mousestate.lY);
}

Mouse::~Mouse()
{
	if (lpDIDeviceMouse)
	{
		lpDIDeviceMouse->Unacquire();	// free keyboard
		lpDIDeviceMouse->Release();		// free device
	}
	if (lpDIObjectMouse)
		lpDIObjectMouse->Release();		// free base COM object
}