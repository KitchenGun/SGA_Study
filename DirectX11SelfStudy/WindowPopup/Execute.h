#pragma once

//Rendering Pipeline 화면에 렌더링되기 위해 가공되는 단계
//IA-VS-RS-PS-OM
//IA=input assembler stage
//-Vertex 정점
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
};

