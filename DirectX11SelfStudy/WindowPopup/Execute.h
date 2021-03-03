#pragma once

//Rendering Pipeline 화면에 렌더링되기 위해 가공되는 단계
//IA-VS-RS-PS-OM
//IA,RS,OM 단계는 코딩 불가능 VS,PS 코딩 가능

//IA=input assembler stage
//-Vertex 정점
//VS = Vertex Shader -> shader : HLSL 고수준의 쉐이더 언어, GLSL
//-Transform
//RS = Rasterizer 3D데이터를 2D데이터로 바꿔주는 것
//NDC 좌표계 사용중 Normalized Device Coordinate 정규화되 장치 좌표계 사용중
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
	class Graphics* graphics = nullptr;//전방선언
	
	VertexColor* vertices = nullptr;
	ID3D11Buffer* vertex_buffer = nullptr;
	ID3D11InputLayout* input_layout = nullptr;

	ID3D11VertexShader* vertex_shader = nullptr;
	ID3DBlob* vs_blob = nullptr;

	ID3D11PixelShader* pixel_shader = nullptr;
	ID3DBlob* ps_blob = nullptr;
};

