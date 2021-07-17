#include "stdafx.h"
#include "Line.h"

Line::Line(Vector3 position, float length, float rotation,Color color)
	:position(position),
	length(length),
	rotation(rotation),
	color(color)
{
	//���� ���� �Է�
	vertices.assign(4, VertexColor());
	vertices[0].position = Vector3(0.0f, 0.0f, 0.0f);
	//vertices[0].color =Red;

	vertices[1].position = Vector3(1.0f, 0.0f, 0.0f);
	//vertices[1].color =Red;
	
	//Ŭ����ȭ �� ��ü ����
	VB = new VertexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();
	CB = new ColorBuffer();
	SetColor(color);
	//��ü���� �Լ� ȣ��
	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	
	VS->Create(L"./_Shaders/VertexColor.hlsl", "VS");
	PS->Create(L"./_Shaders/VertexColor.hlsl", "PS");

	IL->Create(VertexColor::descs, VertexColor::count, VS->GetBlob());

	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);

	//��� ���� �����Ͽ��� y z�� 0�� �ƴ� �ٸ����� �־ 0�� ������ 0�� �ִ´�
	D3DXMatrixScaling(&S, length, 0 , 0);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * R * T;

	WB->SetWorld(world);


}

Line::~Line()
{
	SAFE_DELETE(CB);
	
	SAFE_DELETE(WB);
	
	SAFE_DELETE(IL);
	
	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(VB);
}



void Line::Update()
{
	
}

void Line::Render()
{
	VB->SetIA();
	IL->SetIA();
	//�⺻ ���� ���� ��� ����
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	
	WB->SetVSBuffer(0);
	//���� ����
	CB->SetVSBuffer(2);
	
	VS->SetShader();
	PS->SetShader();
	//�ε��� ���۸� �̿��ؼ� �׸���
	DC->Draw(VB->GetCount(), 0);
}

void Line::Rotation(float rotation)
{
	this->rotation += rotation;
	D3DXMatrixRotationZ(&R,(float)D3DXToRadian(this->rotation));

	world = S * R * T;
	WB->SetWorld(world);//���ο��� transpose����
}

void Line::SetColor(Color color)
{
	this->color = color;
	//���ۿ� �־������
	CB->SetColor(color);
}
