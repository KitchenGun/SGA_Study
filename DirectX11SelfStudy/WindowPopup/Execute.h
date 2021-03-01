#pragma once

//Rendering Pipeline ȭ�鿡 �������Ǳ� ���� �����Ǵ� �ܰ�
//IA-VS-RS-PS-OM
//IA=input assembler stage
//-Vertex ����
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
};

