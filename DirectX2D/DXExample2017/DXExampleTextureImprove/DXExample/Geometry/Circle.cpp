#include "stdafx.h"
#include "Circle.h"

Circle::Circle(Vector3 position, Vector3 size, int segments, Color color)
	:position(position),
	size(size),
	segments(segments),
	color(color)

{
	//���� ���� �Է�
	vertices.assign(segments + 1, VertexColor());
	{
		for (int i = 0; i <= segments; ++i)
		{
			float t = 2 * (float)D3DX_PI*i / segments;//���� ���ϱ�
			
			vertices[i].position = Vector3(cosf(t), -sinf(t), 0); //cosf�� ��ȯ�� float �� cos�� double
			//sin�� -���� ������ �ð�������� �׸��� ���ؼ��̴�.
		}
	}

	//Ŭ����ȭ �� ��ü ����
	VB = new VertexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();
	CB = new ColorBuffer();
	//��ü���� �Լ� ȣ��
	VB->Create(vertices, D3D11_USAGE_IMMUTABLE);

	VS->Create(L"./_Shaders/VertexColor.hlsl", "VS");
	PS->Create(L"./_Shaders/VertexColor.hlsl", "PS");

	IL->Create(VertexColor::descs, VertexColor::count, VS->GetBlob());

	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&T);

	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * T;

	WB->SetWorld(world);
	SetColor(color);

}

Circle::~Circle()
{
	SAFE_DELETE(CB);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(VB);
}

void Circle::SetColor(Color color)
{
	this->color = color;
	CB->SetColor(this->color);
}


void Circle::Update()
{
	
}

void Circle::Render()
{
	VB->SetIA();
	IL->SetIA();
	//�⺻ ���� ���� ��� ����
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	WB->SetVSBuffer(0);
	CB->SetVSBuffer(2);
	VS->SetShader();
	PS->SetShader();
	//�ε��� ���۸� �̿��ؼ� �׸���
	DC->Draw(segments+1, 0);
}


