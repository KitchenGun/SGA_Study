#pragma once

#define NOMINMAX  //DX�� �⺻ �ּ� �ִ� ���� ���� �ʰڴ�
#define no_init_all//2017�� �����ϴ� ���� 2019���� ������

#ifdef _DEBUG
#pragma comment (linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <Windows.h>
#include <assert.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <iostream>
#include <fstream>

using namespace std;

//DX
#include <D3Dcompiler.h>
#include <D3D11.h>
#include <D3DX10math.h>
#include <D3DX11async.h>
//���̺귯�� ����
#pragma comment (lib,"dxgi.lib")
#pragma comment (lib,"d3d11.lib")
#pragma comment (lib,"d3dx11.lib")
#pragma comment (lib,"d3dx10.lib")
#pragma comment (lib,"d3dcompiler.lib")

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR4 Vector4;
typedef D3DXMATRIX Matrix;
typedef D3DXCOLOR Color;

//�̱��� �ش� �߰�
#include "System/Graphics.h"

#define DC Graphics::Get()->GetDC()
#define DEVICE Graphics::Get()->GetDevice()

#define SAFE_DELETE(p){if(p){delete (p);p=nullptr;}}//�����ڿ� ����
#define SAFE_DELETE_ARRAY(p){if(p){delete[](p);p=nullptr;}}//�����ڿ��迭 ����
#define SAFE_RELEASE(p){if(p){p->Release(); p=nullptr;}}//DX �ڿ� ����(Com�������̽��� ����Ƚ���� 1 ����) 

#define ASSERT(p) assert(SUCCEEDED(p));

//âũ��
#define WinMaxWidth 1280
#define WinMaxHeight 720

#define Red		Color(1,0,0,1)
#define Green	Color(0,1,0,1)
#define Blue	Color(0,0,1,1)
#define Black	Color(0,0,0,1)
#define White	Color(1,1,1,1)
#define Yellow	Color(1,1,0,1)
#define Magenta Color(1,0,1,1)//���� ó���� ���ؼ� ����Ÿ ��
#define Cyan	Color(0,1,1,1) // û�ϻ�

//�ڵ鷯
extern HWND handle;

#include "Renders/IA/VertexBuffer.h"
#include "Renders/IA/IndexBuffer.h"
#include "Renders/IA/InputLayout.h"
#include "Renders/Shaders/VertexShader.h"
#include "Renders/Shaders/PixelShader.h"
#include "Renders/Resources/VertexType.h"
#include "Renders/Resources/ShaderBuffer.h"
#include "Renders/Resources/GlobalBuffer.h"

#include "System/Time.h"
#include "System/Mouse.h"
#include "System/Keyboard.h"


#include "Geometry/Line.h"
#include "Geometry/Square.h"
#include "Geometry/Circle.h"

#include "Utilities/Math.h"
#include "Utilities/RenderTexture.h"

#include "Scenes/Scene.h"
