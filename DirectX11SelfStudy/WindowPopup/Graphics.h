#pragma once


class Graphics final
{
public:
	Graphics();
	~Graphics();

	void Initialize();
	void CreateBackBuffer(const uint& width,const uint& height);
	//ID3D11Device 생략가능
	auto GetDevice()-> ID3D11Device* { return device; }
	auto GetDeviceContext() -> ID3D11DeviceContext* { return device_context; }
private:
	ID3D11Device* device						=nullptr;
	ID3D11DeviceContext* device_context			=nullptr;
	IDXGISwapChain* swap_chain					=nullptr;
	//dxgi 그래픽 인터페이스 = 제조사마다 다른 그래픽 카드를 사용하기 위해서 사용한다 정도로 기억 (swapchain=두개의 버퍼를 번갈아가며 반복하며 깜빡임 찢어짐 현상 방지)백버퍼관리
	ID3D11RenderTargetView* render_target_view	=nullptr; //도화지
	//id3d 컴 인터페이스 = 자동으로 할당 요청의 개념         동적할당x 정적할당x
	D3D11_VIEWPORT viewport						= { 0 }; //보여주는 영역
	D3DXCOLOR clear_color						= 0xff555566; //색갈표현
	//dx에서 제공하는 객체
};

//Rendering PipeLine
//IA-VS-RS-PS-OM

//DirectX - API
//OpenGL

//GPU-CPU
