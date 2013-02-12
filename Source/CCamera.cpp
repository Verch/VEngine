#include "CCamera.h"


Camera::Camera(void)
{
	position.x = 0;
	position.y = 0;
	position.z = -5;
	
	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;
}


Camera::~Camera(void)
{
}


void Camera::SetPosition(D3DXVECTOR3 pos)
{
	position = pos;
}

void Camera::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Camera::SetRotation(D3DXVECTOR3 rot)
{
	rotation = rot;
}

void Camera::SetRotation(float rx, float ry, float rz)
{
	rotation.x = rx;
	rotation.y = ry;
	rotation.z = rz;
}

void Camera::Move(D3DXVECTOR3 delta)
{
	position += delta;
}

void Camera::Move(float dx, float dy, float dz)
{
	position.x += dx;
	position.y += dy;
	position.z += dz;
}

void Camera::Rotate(D3DXVECTOR3 rot)
{
	rotation += rot;
}

void Camera::Rotate(float rx, float ry, float rz)
{
	rotation.x += rx;
	rotation.y += ry;
	rotation.z += rz;
}

D3DXVECTOR3 Camera::GetPosition()
{
	return position;
}

D3DXVECTOR3 Camera::GetRotation()
{
	return rotation;
}

void Camera::Render()
{
	D3DXVECTOR3 up;
	D3DXVECTOR3 target;
	D3DXMATRIX rotMatrix;
	float yaw, pitch, roll;

	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	target.x = 0;
	target.y = 0;
	target.z = 1;

	//create the rotation matrix based on the yaw(y) pitch(x) and roll(z) angles;
	D3DXMatrixRotationYawPitchRoll(&rotMatrix, D3DXToRadian(rotation.y), D3DXToRadian(rotation.x), D3DXToRadian(rotation.z));

	//transform the vectors so that they reflect the rotations that have been made
	D3DXVec3TransformCoord(&target, &target, &rotMatrix);
	D3DXVec3TransformCoord(&up, &up, &rotMatrix);

	//move the target to be infront of the camera
	target += position;

	D3DXMatrixLookAtLH(&viewMatrix, &position, &target, &up);
}

D3DXMATRIX& Camera::GetViewMatrix()
{
	return viewMatrix;
}