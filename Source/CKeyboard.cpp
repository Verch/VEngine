#include <CKeyboard.h>

Keyboard::Keyboard(HINSTANCE hInst, HWND hWnd)
{
	this->hInstance = hInst;
	this->hWindow = hWnd;
}

bool Keyboard::Launch()
{
	/* Create Direct Input Object */
	hr = DirectInput8Create(hInstance,	// instance of creating app
		DIRECTINPUT_VERSION,	// vers of DI that app requires
		IID_IDirectInput8,		// indefiner of the required interface
		reinterpret_cast<void **>(&lpDIObjectKeyboard),	// pointer to soon-to-be-created DI object
		NULL);						// pUnkOuter
	if (FAILED(hr))	return false;

	/* Create Direct Input Device */
	hr = lpDIObjectKeyboard->CreateDevice(GUID_SysKeyboard,		// keyboard, mouse...
		&lpDIDeviceKeyboard,	// pointer to soon-to-be-created DI device
		NULL);		// pUnkOuter
	if (FAILED(hr)) return false;

	/* Set Direct Input Data Format */
	hr = lpDIDeviceKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr)) return false;
	
	/* Set input control  */
	hr = lpDIDeviceKeyboard->SetCooperativeLevel(hWindow,
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (FAILED(hr)) return false;

	/* Get keyboard control to app  */
	hr = lpDIDeviceKeyboard->Acquire();
	if (FAILED(hr)) return false;

	return true;	
}

bool Keyboard::Read()
{
	hr = lpDIDeviceKeyboard->GetDeviceState(KEYSTATEBYTES*sizeof(UCHAR),
		static_cast<LPVOID>(keystate));
	if (FAILED(hr)) return false;

	return true;
}

bool Keyboard::KeyDown(UCHAR key)
{
	if (keystate[key]&0x80) return true;
	else return false;
}

Keyboard::~Keyboard()
{
	if (lpDIDeviceKeyboard)
	{
		lpDIDeviceKeyboard->Unacquire();	// free keyboard
		lpDIDeviceKeyboard->Release();		// free device
	}
	if (lpDIObjectKeyboard)
		lpDIObjectKeyboard->Release();		// free base COM object
}