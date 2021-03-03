#pragma once

//Rendering Pipeline ȭ�鿡 �������Ǳ� ���� �����Ǵ� �ܰ�
//IA-VS-RS-PS-OM
//IA,RS,OM �ܰ�� �ڵ� �Ұ��� VS,PS �ڵ� ����

//IA=input assembler stage
//-Vertex ����
//VS = Vertex Shader -> shader : HLSL ������� ���̴� ���, GLSL
//-Transform
//RS = Rasterizer 3D�����͸� 2D�����ͷ� �ٲ��ִ� ��
//NDC ��ǥ�� ����� Normalized Device Coordinate ����ȭ�� ��ġ ��ǥ�� �����
//PS = Pixel Shader

struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR color;
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
	
	VertexColor* vertices = nullptr;
	ID3D11Buffer* vertex_buffer = nullptr;
	ID3D11InputLayout* input_layout = nullptr;

	ID3D11VertexShader* vertex_shader = nullptr;
	ID3DBlob* vs_blob = nullptr;

	ID3D11PixelShader* pixel_shader = nullptr;
	ID3DBlob* ps_blob = nullptr;
};

