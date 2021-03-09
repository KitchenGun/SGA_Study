#pragma once

//Rendering Pipeline ȭ�鿡 �������Ǳ� ���� �����Ǵ� �ܰ�
//IA-VS-RS-PS-OM
//IA,RS,OM �ܰ�� �ڵ� �Ұ��� VS,PS �ڵ� ����

//IA=input assembler stage
//-Vertex ����

//VS = Vertex Shader -> shader : HLSL ������� ���̴� ���, GLSL
//-Transform
//Local			����� ��ǥ 
//World			���� ��ǥ
//View			�ü��� ���̴� ����
//Projection	��������   3D������->2D������ ������ ���ߴ°�  
//Clip			homogeneous space ���� ���� (1,0,0,0) ���� ��ǥ ǥ��  w�� 0�̸� ���� w�� 1�̻��̸� ��ġ�� ǥ��
// ������ ��ķ� ǥ���ǰ� local world view projection ������ �귯����

//RS = Rasterizer 3D�����͸� 2D�����ͷ� �ٲ��ִ� ��
//NDC ��ǥ�� ����� Normalized Device Coordinate ����ȭ�� ��ġ ��ǥ�� �����
//back-face culling ������ �ʴ� �� ����
//viewprot Transform
//Scan Transform

//PS = Pixel Shader


//NDC			euclidean space	ǥ�� ���� 
//Viewport		

struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR color;
};

struct VertexTexture
{
	D3DXVECTOR3 position;
	D3DXVECTOR2 uv;		//�ؽ�ó ��ǥ�� //����ȭ�Ǿ�����

};

struct TRANSFORM_DATA
{
	D3DXMATRIX world;		//4x4
	D3DXMATRIX view;		//4x4
	D3DXMATRIX projection;	//4x4
};

class Execute final
{
public:
	Execute();
	~Execute();

	void Update();
	void Render();

private:
	class Graphics* graphics = nullptr;//���漱��
	
	VertexTexture* vertices = nullptr;
	ID3D11Buffer* vertex_buffer = nullptr;

	uint* indices = nullptr;
	ID3D11Buffer* index_buffer;

	ID3D11InputLayout* input_layout = nullptr;

	ID3D11VertexShader* vertex_shader = nullptr;
	ID3DBlob* vs_blob = nullptr;

	ID3D11PixelShader* pixel_shader = nullptr;
	ID3DBlob* ps_blob = nullptr;

	D3DXMATRIX world;		//4x4
	D3DXMATRIX view;		//4x4
	D3DXMATRIX projection;	//4x4
	/*4x4 �׵� ���  //����� �׻� ������ķ� �ʱ�ȭ �ʿ�  //������ Ŀ���� ���� �����͵� Ŀ����//�����̵��� ���� �����͵� �̵�
	
	x	1 0 0 0	//x�� ���ϴ� ���⺤��
	y	0 1 0 0	//y�� ���ϴ� ���⺤��
	z	0 0 1 0	//z�� ���ϴ� ���⺤��
	w	0 0 0 1 //�߽���ġ + ��ġ&�����ǹ�

	opengl  RH��ǥ�� 
	directx LH��ǥ��

	*/
	TRANSFORM_DATA cpu_buffer;
	ID3D11Buffer* gpu_buffer = nullptr;//constant buffer

	ID3D11RasterizerState* rasterizer_state = nullptr;

	ID3D11ShaderResourceView* shader_resource;
	//Texture
	//ID3D11Texture2D   �뵵�� ��Ȯ���� ����
	//Rander Target view
	//Depth Stencil View		���� ���ٽ� ��
	//Shader Resource View
	//Unordered Access View		�������� ���ٺ�
};

