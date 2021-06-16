#pragma once

#define NOMINMAX  //DX의 기본 최소 최대 정의 쓰지 않겠다
#define no_init_all//2017만 존재하는 버그 2019에서 수정됨

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
//라이브러리 참조
#pragma comment (lib,"dxgi.lib")
#pragma comment (lib,"d3d11.lib")
#pragma comment (lib,"d3dx11.lib")
#pragma comment (lib,"d3dx10.lib")
#pragma comment (lib,"d3dcompiler.lib")
//싱글톤 해더 추가
#include "System/Graphics.h"

#define DC Graphics::Get()->GetDC()
#define DEVICE Graphics::Get()->GetDevice()

#define SAFE_DELETE(p){if(p){delete (p);p=nullptr;}}//동적자원 해제
#define SAFE_DELETE_ARRAY(p){if(p){delete[](p);p=nullptr;}}//동적자원배열 해제
#define SAFE_RELEASE(p){if(p){p->Release(); p=nullptr;}}//DX 자원 해제(Com인터페이스의 참조횟수를 1 줄임) 

#define ASSERT(p) assert(SUCCEEDED(p));

//창크기
#define WinMaxWidth 1280
#define WinMaxHeight 720
//핸들러
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


#include "Geometry/Square.h"
#include "Geometry/Circle.h"

