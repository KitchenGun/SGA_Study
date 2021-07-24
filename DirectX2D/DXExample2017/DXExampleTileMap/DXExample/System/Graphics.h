#pragma once
//�̱��� 
//GPU�ٷ�� ���� �ٽ� = DX
//���̴� ǥ���� �ϱ����ؼ� ����ϴ� �� HLSL

//���漱�� //���ݰ��� ���� ���� Ŭ������ Graphics Ŭ�������� ����ϱ� ����
/*
���� ������ �� ��� Ŭ������ ���縸 ������Ű�� ���̱� ������ �����ͷ� �ۿ� �������� ���Ѵ�.
���漱���� ����ϴ� ������ �����Ϸ��� ������Ͽ� ������ ���ܵ� ��������� ���������� �̷���� ���� �ʱ� ������ ȿ������ �ӵ��� ������Ű���� ����Ѵ�.
���� �������� �Ǵ� ������ ���⵵ �Ѵ�.
*/
class D3DEnumAdapterInfo;
class D3DEnumOutputInfo;

class Graphics : public Singleton<Graphics>
{
public:
	friend class Singleton<Graphics>;
public:
	ID3D11Device*GetDevice() { return device; }
	ID3D11DeviceContext* GetDC() { return deviceContext; }

	void Resize(const UINT& width, const UINT& height);
	void SetViewport(const UINT& width, const UINT& height);

	void Begin();
	void End();

	void SetViewport();
	Color GetClearColor() { return clearColor; }
	void SetBackBufferToRTV();

private:
	void CreateSwapChain();
	void CreateRenderTargetView();
	void DeleteSurface();

private:
	Graphics();
	~Graphics();

	static Graphics* instance;

	void EnumerateAdapters();										//�׷��� ī�� ����
	bool EnumerateAdapterOutput(D3DEnumAdapterInfo* adapterInfos);	//�׷��� ī���� ������ ���� ����� ���� �б�
	void SetGPUInfo();
	
private:
	ID3D11Device* device=nullptr;				//�ڿ��� �����ϴ� ����  desc(���� �ֹ���)�� ������ ����
												//com interface (componant object model)���ο� �̹� �Ҵ�Ǿ �������� �ʴ� ����  �տ� I�� �پ��ִ� ���  ������ �ƴ϶� �����ϴ� �� 
	ID3D11DeviceContext* deviceContext=nullptr;	//�׸��׸��� ��
												//safe release�� ��������
	IDXGISwapChain* swapChain = nullptr;		//���� ���۸� ���ִ� ��ü //����Ʈ�� ���� ��ü���ִ� ü��
	ID3D11RenderTargetView* rtv = nullptr;		//����ۿ� ����Ǿ��ִ� ȭ�鿡 rtvȿ���� ����� �����Ͽ� ����ü���� �����ϸ� ����Ǿ� �����
												//��Ʈ�� ���� ȿ��
	D3D11_VIEWPORT viewport = { 0 };			//�������� ����	
	Color clearColor = 0xff555566;			//�ʱ�� 
	//���� �ֱ⸦ ���� �ʿ��� ����
	UINT numerator;					//����
	UINT denominator;				//�и�
	//�׷���ī�� ��������
	UINT gpuMemorySize;
	wstring gpuDescription;
	//��ǻ���� ��� �׷��� ī���������� ���� ���·� ����
	vector<D3DEnumAdapterInfo*> adapterInfos;
	//�ʿ��� �׷���ī���� ������ �ﰢ ȣ���ϱ����� �����Ҽ��ִ� �ε���
	int selectedAdapterIndex;

	bool bVsync = true; // ���� ����ȭ ����Ϳ� ���缭 ���� ��� 60hz��� �����ϸ��//���� ����Ϳ� �ֻ����� �����   
	//Ƽ� ������ �����ϱ� ���ؼ� ���(����� �ֻ����� �׷���ī���� ������ ���̳��� ����� �����̴�)
	
};

//////////////////////////////////////////////////////////////////////////////////////////
class D3DEnumAdapterInfo//�׷��� ī�� ����
{
public:
	D3DEnumAdapterInfo()=default;
	~D3DEnumAdapterInfo();

	UINT adapterOrdinal = 0;
	IDXGIAdapter1* adapter = nullptr;		//�ٽ� com interface ���÷��� ���� �ý��� ���� gpu�� ���� �� �޸𸮸� �޾ƿü��ִ�.
	DXGI_ADAPTER_DESC1 adapterDesc = { 0 };

	D3DEnumOutputInfo* outputInfo = nullptr;

	
private:
	const D3DEnumAdapterInfo& operator = (const D3DEnumAdapterInfo& rhs);
};

class D3DEnumOutputInfo//����� ����
{
public:
	D3DEnumOutputInfo() = default;
	~D3DEnumOutputInfo();

	IDXGIOutput* output = nullptr;			//�ٽ� com interface ����� ������ �޾ƿ��µ� �����
	DXGI_OUTPUT_DESC outputDesc = { 0 };
	//�ֻ����� ��������
	UINT numerator;
	UINT denominator;

private:
	const D3DEnumOutputInfo &operator = (const D3DEnumOutputInfo& rhs);
};