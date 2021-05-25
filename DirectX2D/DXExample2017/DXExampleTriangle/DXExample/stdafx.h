#pragma once

#define no_init_all//2017만 존재하는 버그 2019에서 수정됨

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
//라이브러리 참조
#pragma comment (lib,"dxgi.lib")
#pragma comment (lib,"d3d11.lib")
#pragma comment (lib,"d3dx11.lib")
#pragma comment (lib,"d3dx10.lib")
#pragma comment (lib,"d3dcompiler.lib")
//
#define SAFE_DELETE(p){if(p){delete (p);p=nullptr;}}
#define SAFE_DELETE_ARRAY(p){if(p){delete[](p);p=nullptr;}}
#define SAFE_RELEASE(p){if(p){p->Release(); p=nullptr;}}
//창크기
#define WinMaxWidth 1280
#define WinMaxHeight 720
//핸들러
extern HWND handle;