// OpenGlCppCode.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <exception>
#include <map>
#include <memory>

#include <chrono>
#include <Windows.h>

#include "D3DRender.h"

#pragma comment(lib, "D3d11.lib")
#pragma comment(lib, "D2d1.lib")
#pragma comment(lib, "Dwrite.lib")

#define CPP_EXPORTS_API
#ifdef CPP_EXPORTS_API
#define CPP_API extern "C" __declspec(dllexport)
#else
#define CPP_API __declspec(dllimport)
#endif
using namespace std; 
extern map<HWND, shared_ptr<DX::Directx11>>* device = NULL;
CPP_API void InitDirectX(int handle)
{
	(*device)[(HWND) handle] = make_shared<DX::Directx11>((HWND)handle);
}

CPP_API void PrepareScene(int handle,int w,int h)
{
	auto finded = device->find((HWND) handle);
	if (finded != device->end())
	{
		finded->second->CreateTarget(w, h);
		finded->second->ClearAll();
		//vector<array<array<int, 3>, 2>> triangles;

		//array<array<int, 3>, 2> triangle;
		//triangle[0] = { 0, 2, 1 };
		//triangle[1] = { 128, 0, 128 };
		//triangles.push_back(triangle);

		//vector<array<double, 3>> xyz;
		//xyz.resize(3);
		//xyz[0] = { 0, 0, 0.5 };
		//xyz[1] = { 1, 0, 0.5 };
		//xyz[2] = { 0, 1, 0.5 };

		//vector<array<double, 3>> normals;
		//normals.resize(3);
		//normals[0] = { 0, 0, 1 };
		//normals[1] = { 0, 0, 1 };
		//normals[2] = { 0, 0, 1 };

		vector<array<array<int, 3>, 2>> triangles;

		// 1 square
		array<array<int, 3>, 2> triangle;
		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		array<array<int, 3>, 2> triangle1;
		triangle1[0] = { 1, 2, 3 };
		triangle1[1] = { 128, 0, 128 };
		triangles.push_back(triangle1);

		// 2 square
		array<array<int, 3>, 2> triangle2;
		triangle2[0] = { 0, 1, 4 };
		triangle2[1] = { 128, 0, 128 };
		triangles.push_back(triangle2);

		array<array<int, 3>, 2> triangle3;
		triangle3[0] = { 1, 4, 5 };
		triangle3[1] = { 128, 0, 128 };
		triangles.push_back(triangle3);

		// 3 square
		array<array<int, 3>, 2> triangle4;
		triangle4[0] = { 3, 1, 7 };
		triangle4[1] = { 128, 0, 128 };
		triangles.push_back(triangle4);

		array<array<int, 3>, 2> triangle5;
		triangle5[0] = { 1, 7, 5 };
		triangle5[1] = { 128, 0, 128 };
		triangles.push_back(triangle5);

		// 4 square
		array<array<int, 3>, 2> triangle6;
		triangle6[0] = { 0, 2, 4 };
		triangle6[1] = { 128, 0, 128 };
		triangles.push_back(triangle6);

		array<array<int, 3>, 2> triangle7;
		triangle7[0] = { 2, 4, 6 };
		triangle7[1] = { 128, 0, 128 };
		triangles.push_back(triangle7);

		// 5 square
		array<array<int, 3>, 2> triangle8;
		triangle8[0] = { 2, 3, 7 };
		triangle8[1] = { 128, 0, 128 };
		triangles.push_back(triangle8);

		array<array<int, 3>, 2> triangle9;
		triangle9[0] = { 2, 7, 6 };
		triangle9[1] = { 128, 0, 128 };
		triangles.push_back(triangle9);

		// 6 square
		array<array<int, 3>, 2> triangle10;
		triangle10[0] = { 4, 5, 7 };
		triangle10[1] = { 128, 0, 128 };
		triangles.push_back(triangle10);

		array<array<int, 3>, 2> triangle11;
		triangle11[0] = { 7, 6, 4 };
		triangle11[1] = { 128, 0, 128 };
		triangles.push_back(triangle11);

		vector<array<double, 3>> xyz;
		xyz.resize(8);
		xyz[0] = { -1, -1, -1 };
		xyz[1] = { 1, -1, -1 };
		xyz[2] = { -1, 1, -1 };
		xyz[3] = { 1, 1, -1 };
		xyz[4] = { -1, -1, 1 };
		xyz[5] = { 1, -1, 1 };
		xyz[6] = { -1, 1, 1 };
		xyz[7] = { 1, 1, 1 };

		vector<array<double, 3>> normals;
		normals.resize(8);
		normals[0] = { 0, 1, 0 };
		normals[1] = { 0, 1, 0 };
		normals[2] = { 0, 1, 0 };
		normals[3] = { 0, 1, 0 };
		normals[4] = { 0, 1, 0 };
		normals[5] = { 0, 1, 0 };
		normals[6] = { 0, 1, 0 };
		normals[7] = { 0, 1, 0 };

		finded->second->RenderStart();

		auto unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		finded->second->RenderSavedData();
		finded->second->EndRender();
	}
}
CPP_API void RenderScene(int handle)
{
	auto finded = device->find((HWND) handle);
	if (finded != device->end())
	{
		//DirectX::XMStoreFloat4x4(&(finded->second->ModelViewMatrix), DirectX::XMMatrixIdentity());
		//DirectX::XMStoreFloat4x4(&(finded->second->ProjectionMatrix), DirectX::XMMatrixIdentity());

		static auto startTime = std::chrono::high_resolution_clock::now();
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> elapsed = currentTime - startTime;
		float angle = elapsed.count() * 0.9f;

		DirectX::XMMATRIX rotY = DirectX::XMMatrixRotationY(angle);
		DirectX::XMMATRIX rotX = DirectX::XMMatrixRotationX(angle * 0.7f);
		DirectX::XMMATRIX world = rotX * rotY;
		
		DirectX::XMMATRIX view = DirectX::XMMatrixTranslation(0.0f, 0.0f, 5.0f);

		DirectX::XMMATRIX modelView = world * view;
		DirectX::XMStoreFloat4x4(&(finded->second->ModelViewMatrix), modelView);

		float aspectRatio = (float)finded->second->width / (float)finded->second->height;
		if (aspectRatio == 0) aspectRatio = 1.0f;

		DirectX::XMMATRIX projection = DirectX::XMMatrixPerspectiveFovLH(
			DirectX::XM_PIDIV4, 
			aspectRatio,
			0.1f, 
			100.0f 
		);
		DirectX::XMStoreFloat4x4(&(finded->second->ProjectionMatrix), projection);

		finded->second->RenderSavedData();
		finded->second->EndRender();

		InvalidateRect((HWND)handle, NULL, FALSE);
	}
}
