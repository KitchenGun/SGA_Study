#pragma once

#define no_init_all//2017�� �����ϴ� ���� 2019���� ������

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
//
#define SAFE_DELETE(p){if(p){delete (p);p=nullptr;}}
#define SAFE_DELETE_ARRAY(p){if(p){delete[](p);p=nullptr;}}
#define SAFE_RELEASE(p){if(p){p->Release(); p=nullptr;}}
//âũ��
#define WinMaxWidth 1280
#define WinMaxHeight 720
//�ڵ鷯
extern HWND handle;