#pragma once

#include "DirectX/d3d9.h"
#include "DirectX/d3dx9.h"
#include "DirectX/d3dx9math.h"
#include <windows.h>
//#include <mmsystem.h> // vbv?

#pragma comment(lib,"d3d9.lib") 
#pragma comment(lib,"d3dx9.lib")
//#pragma comment(lib,"dxguid.lib") // vbv?
//#pragma comment(lib,"dsound.lib") 
//#pragma comment(lib,"winmm.lib")	// vbv?

class Camera
{
public:
	Camera(void);
	~Camera(void);
	
	void SetPosition(D3DXVECTOR3 pos);
	void SetPosition(float x, float y, float z);

	void SetRotation(D3DXVECTOR3 rot);
	void SetRotation(float rx, float ry, float rz);

	void Move(D3DXVECTOR3 delta);
	void Move(float dx, float dy, float dz);

	void Rotate(D3DXVECTOR3 delta);
	void Rotate(float dx, float dy, float dz);

	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetRotation();

	void Render();
	D3DXMATRIX& GetViewMatrix();

private:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXMATRIX viewMatrix;
};

