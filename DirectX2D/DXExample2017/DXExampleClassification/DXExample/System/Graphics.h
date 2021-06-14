#pragma once
//�̱��� 
//GPU�ٷ�� ���� �ٽ� = DX
//���̴� ǥ���� �ϱ����ؼ� ����ϴ� �� HLSL

class Graphics
{
public:
	static void Create();
	static void Delete();
	static Graphics* Get();

public:
	void Init();
	void CreateBackBuffer();

	void Begin();
	void End();

	ID3D11Device*GetDevice() { return device; }
	ID3D11DeviceContext* GetDC() { return deviceContext; }


private:
	Graphics();
	~Graphics();

	static Graphics* instance;
private:
	ID3D11Device* device=nullptr;					//�ڿ��� �����ϴ� ����  desc(���� �ֹ���)�� ������ ����
													//com interface (componant object model)���ο� �̹� �Ҵ�Ǿ �������� �ʴ� ����  �տ� I�� �پ��ִ� ���  ������ �ƴ϶� �����ϴ� �� 
	ID3D11DeviceContext* deviceContext=nullptr;		//�׸��׸��� ��
													//safe release�� ��������
	IDXGISwapChain* swapChain = nullptr;			//���� ���۸� ���ִ� ��ü //����Ʈ�� ���� ��ü���ִ� ü��
	ID3D11RenderTargetView* rtv = nullptr;			//����ۿ� ����Ǿ��ִ� ȭ�鿡 rtvȿ���� ����� �����Ͽ� ����ü���� �����ϸ� ����Ǿ� �����
													//��Ʈ�� ���� ȿ��
	D3D11_VIEWPORT viewport = { 0 };				//�������� ����	
	D3DXCOLOR clearColor = 0xff555566;				//�ʱ�� 

};

//////////////////////////////////////////////////////////////////////////////////////////
class D3DEnumAdapterInfo
{
public:
	D3DEnumAdapterInfo()=default;
	~D3DEnumAdapterInfo();

	UINT adapterOrdinal = 0;
	IDXGIAdapter* adapter = nullptr;
	DXGI_ADAPTER_DESC1 adapterDesc = { 0 };

	D3DEnumOutputInfo* outputInfo = nullptr;
private:
	const D3DEnumAdapterInfo& operator = (const D3DEnumAdapterInfo& rhs);
};

class D3DEnumOutputInfo
{
public:
	D3DEnumOutputInfo() = default;
	~D3DEnumOutputInfo();

	IDXGIOutput* output = nullptr;
	DXGI_OUTPUT_DESC outputDesc = { 0 };

private:
	const D3DEnumOutputInfo &operator = (const D3DEnumOutputInfo& rhs);
};