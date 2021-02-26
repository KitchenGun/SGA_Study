#include "stdafx.h"
#include "Graphics.h"
#include "Window.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
	//dangling pointer
	//포인터가 해제된 구역을 메모리가 가리킬 경우를 방지하기위해서 생성순서대로 삭제
	SAFE_RELEASE(render_target_view);
	SAFE_RELEASE(device);
	SAFE_RELEASE(device_context);
	SAFE_RELEASE(swap_chain);
}

void Graphics::Initialize()
{
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));
	desc.BufferDesc.Width = 0;
	desc.BufferDesc.Height = 0;
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	desc.BufferCount = 1;
	//SSAA MSAA 샘플링
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.OutputWindow = Window::global_handle;
	//창모드
	desc.Windowed = true;
	desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	std::vector<D3D_FEATURE_LEVEL> feature_levels
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};
	
	auto hr = D3D11CreateDeviceAndSwapChain
	(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		feature_levels.data(),
		feature_levels.size(),
		D3D11_SDK_VERSION,
		&desc,
		&swap_chain,
		&device,
		nullptr,
		&device_context
	);
	assert(SUCCEEDED(hr));
}

void Graphics::CreateBackBuffer(const uint& width, const uint& height)
{
	auto hr = swap_chain->ResizeBuffers
	(
		0,
		width,
		height,
		DXGI_FORMAT_UNKNOWN,
		0
	);
	assert(SUCCEEDED(hr));

	//모든ID3D11은 ID3D11Resource를 상속받는다.
	//ID3D11Buffer     ID3D11Texture1D,ID3D11Texture2D,ID3D11Texture3D
	ID3D11Texture2D* back_buffer = nullptr;//swap체인통해서 backbuffer를 알아낼수있음

	hr = swap_chain->GetBuffer
	(
		0,
		__uuidof(ID3D11Texture2D),//IID_ID3D11Texture2D,   //UUID, GUID 16바이트 데이터
		reinterpret_cast<void**>(&back_buffer)
	);
	assert(SUCCEEDED(hr));

	hr = device->CreateRenderTargetView
	(
		back_buffer,
		nullptr,
		&render_target_view
	);
	assert(SUCCEEDED(hr));

	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = static_cast<float>(width);
	viewport.Height = static_cast<float>(height);
	viewport.MaxDepth = 1.0f;
	viewport.MinDepth = 0.0f;

	SAFE_RELEASE(back_buffer);

}
