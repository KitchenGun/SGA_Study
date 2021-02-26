#pragma once


class Graphics final
{
public:
	Graphics();
	~Graphics();

	void Initialize();
	void CreateBackBuffer(const uint& width,const uint& height);
	//ID3D11Device ��������
	auto GetDevice()-> ID3D11Device* { return device; }
	auto GetDeviceContext() -> ID3D11DeviceContext* { return device_context; }
private:
	ID3D11Device* device						=nullptr;
	ID3D11DeviceContext* device_context			=nullptr;
	IDXGISwapChain* swap_chain					=nullptr;
	//dxgi �׷��� �������̽� = �����縶�� �ٸ� �׷��� ī�带 ����ϱ� ���ؼ� ����Ѵ� ������ ��� (swapchain=�ΰ��� ���۸� �����ư��� �ݺ��ϸ� ������ ������ ���� ����)����۰���
	ID3D11RenderTargetView* render_target_view	=nullptr; //��ȭ��
	//id3d �� �������̽� = �ڵ����� �Ҵ� ��û�� ����         �����Ҵ�x �����Ҵ�x
	D3D11_VIEWPORT viewport						= { 0 }; //�����ִ� ����
	D3DXCOLOR clear_color						= 0xff555566; //����ǥ��
	//dx���� �����ϴ� ��ü
};

//Rendering PipeLine
//IA-VS-RS-PS-OM

//DirectX - API
//OpenGL

//GPU-CPU
