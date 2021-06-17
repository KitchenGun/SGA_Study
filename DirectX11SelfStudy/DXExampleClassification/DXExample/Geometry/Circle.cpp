#include "stdafx.h"
#include "Circle.h"

Circle::Circle(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation)
	:position(position),
	size(size),
	rotation(rotation)
{
	//정점 정보 입력
	vertices.assign(361, VertexColor());
	indices.assign(361,sizeof(UINT));
	for (int i = 0; i <= 360; ++i)
	{
		vertices[i].position = D3DXVECTOR3(0.5f*(float)cos(D3DXToRadian(i)), 0.5f*(float)sin(D3DXToRadian(i)), 0.0f);
		vertices[i].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		indices[i]=i;
	}

	//클래스화 한 객체 생성
	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();
	CB = new ColorBuffer();
	//객체에서 함수 호출
	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);

	VS->Create(L"./_Shaders/VertexColor.hlsl", "VS");
	PS->Create(L"./_Shaders/VertexColor.hlsl", "PS");

	IL->Create(VertexColor::descs, VertexColor::count, VS->GetBlob());

	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);

	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * R * T;

	WB->SetWorld(world);
	TransformVertices();


}

Circle::~Circle()
{
	SAFE_DELETE(CB);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void Circle::Move(D3DXVECTOR3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}

void Circle::Update()
{
	//버텍스 버퍼를 갱신
	D3D11_MAPPED_SUBRESOURCE subResource;
	DC->Map
	(
		VB->GetResource(),
		0,
		D3D11_MAP_WRITE_DISCARD,
		0,
		&subResource
	);
	//색상변환
	for (VertexColor&v : vertices)
	{
		v.color = D3DXCOLOR(1, 0, 0, 1);
	}
	//버퍼내 정점 저장
	//객체의 pData 멤버는 버퍼내 데이터의 시작에 대한 포인터입니다.
	memcpy(subResource.pData, vertices.data(), sizeof(VertexColor)*vertices.size());
	DC->Unmap(VB->GetResource(), 0);
}

void Circle::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	//기본 도형 형성 방법 지정
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	WB->SetVSBuffer(0);
	VS->SetShader();
	PS->SetShader();
	//인덱스 버퍼를 이용해서 그리기
	DC->DrawIndexed(IB->GetCount(), 0, 0);
}

void Circle::TransformVertices()
{
	//D3DXVec3TransformNormal() //벡터 이동   //지정된 행렬에 의해 3D 벡터 법선을 변환 한다.
	D3DXVec3TransformCoord//정점 이동   //충돌을 체크하기 위한 좌표저장
	(//지정된 행렬에 의해 3D 벡터를 변환 해, 그 결과를 w = 1 에 투영 한다.
		&r.LT,
		&vertices[1].position,
		&world
	);
	D3DXVec3TransformCoord//정점 이동
	(
		&r.RB,
		&vertices[2].position,
		&world
	);
}
