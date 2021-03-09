#pragma once

//Rendering Pipeline 화면에 렌더링되기 위해 가공되는 단계
//IA-VS-RS-PS-OM
//IA,RS,OM 단계는 코딩 불가능 VS,PS 코딩 가능

//IA=input assembler stage
//-Vertex 정점

//VS = Vertex Shader -> shader : HLSL 고수준의 쉐이더 언어, GLSL
//-Transform
//Local			설계상 좌표 
//World			월드 좌표
//View			시선에 보이는 공간
//Projection	투영공간   3D데이터->2D데이터 한차원 낮추는것  
//Clip			homogeneous space 동차 공간 (1,0,0,0) 으로 좌표 표현  w가 0이면 방향 w가 1이상이면 위치를 표현
// 공간은 행렬로 표현되고 local world view projection 순으로 흘러간다

//RS = Rasterizer 3D데이터를 2D데이터로 바꿔주는 것
//NDC 좌표계 사용중 Normalized Device Coordinate 정규화되 장치 좌표계 사용중
//back-face culling 보이지 않는 면 제거
//viewprot Transform
//Scan Transform

//PS = Pixel Shader


//NDC			euclidean space	표준 공간 
//Viewport		

struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR color;
};

struct VertexTexture
{
	D3DXVECTOR3 position;
	D3DXVECTOR2 uv;		//텍스처 좌표계 //정규화되어있음

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
	class Graphics* graphics = nullptr;//전방선언
	
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
	/*4x4 항등 행렬  //행렬은 항상 단위행렬로 초기화 필요  //공간이 커지면 안의 데이터도 커진다//공간이동시 안의 데이터도 이동
	
	x	1 0 0 0	//x축 향하는 방향벡터
	y	0 1 0 0	//y축 항하는 방향벡터
	z	0 0 1 0	//z축 향하는 방향벡터
	w	0 0 0 1 //중심위치 + 위치&방향의미

	opengl  RH좌표계 
	directx LH좌표계

	*/
	TRANSFORM_DATA cpu_buffer;
	ID3D11Buffer* gpu_buffer = nullptr;//constant buffer

	ID3D11RasterizerState* rasterizer_state = nullptr;

	ID3D11ShaderResourceView* shader_resource;
	//Texture
	//ID3D11Texture2D   용도가 명확하지 않음
	//Rander Target view
	//Depth Stencil View		깊이 스텐실 뷰
	//Shader Resource View
	//Unordered Access View		순서없는 접근뷰
};

