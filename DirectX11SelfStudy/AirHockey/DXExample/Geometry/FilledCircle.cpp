#include "stdafx.h"
#include "FilledCircle.h"

FilledCircle::FilledCircle(Vector3 position, Vector3 size, int segments, Color color)
	:position(position),
	size(size),
	segments(segments),
	color(color)

{
	//���� ���� �Է�
	vertices.assign(segments+ 1, VertexColor());
	{
		vertices[0].position = Vector3(0, 0, 0);
		for (int i = 0; i < segments; i++)
		{
			float t = 2 * (float)D3DX_PI*i / segments;//���� ���ϱ�
			vertices[i+1].position = Vector3(cosf(t), -sinf(t), 0);
			//sin�� -���� ������ �ð�������� �׸��� ���ؼ��̴�.
		}
	}
	indices.assign(segments * 3, sizeof(UINT));
	{//012023034....������ ���ؼ� ���� for��
		for (int i = 0; i < segments; i++)
		{
			indices[i * 3] = 0;
			indices[i * 3 + 1] = i + 1;
			if (i == segments - 1)//���� �ּ�ȭ �۾� if������ ������ ������ �������� �̿��ϴ� ���
			{
				indices[i * 3 + 2] = 1;
			}
			else
			{
				indices[i * 3 + 2] = i + 2;
			}
		}
	}
	//Ŭ����ȭ �� ��ü ����
	VB = new VertexBuffer();
	IB = new IndexBuffer();
	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();
	CB = new ColorBuffer();
	//��ü���� �Լ� ȣ��
	VB->Create(vertices, D3D11_USAGE_IMMUTABLE);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);
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

FilledCircle::~FilledCircle()
{
	SAFE_DELETE(CB);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);
	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void FilledCircle::SetColor(Color color)
{
	this->color = color;
	CB->SetColor(this->color);
}


void FilledCircle::Update()
{
	
}

void FilledCircle::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	//�⺻ ���� ���� ��� ����
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	WB->SetVSBuffer(0);
	CB->SetVSBuffer(2);
	VS->SetShader();
	PS->SetShader();
	//�ε��� ���۸� �̿��ؼ� �׸���
	DC->DrawIndexed(IB->GetCount(),0, 0);
}

void FilledCircle::TransformVertices()
{
	ce.POINT = position;

	ce.RADIUS = size.x;
}


