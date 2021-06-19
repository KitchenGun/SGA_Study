#include "stdafx.h"
#include "Player.h"

Player::Player(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation) : Square(position,size,rotation)
{

}

Player::~Player()
{

}

void Player::PlayerCtrl()
{
	//상하
	if (Keyboard::Get()->Press('W'))
	{
		if (Math::TouchEdge(this) != Direction::TOP&&Math::TouchEdge(this) != Direction::TL&&Math::TouchEdge(this) != Direction::TR)
		{
			this->Move({ 0,10,0 });
			isMoveVertical = true;
		}
	}
	else if (Keyboard::Get()->Press('S'))
	{
		if (Math::TouchEdge(this) != Direction::BOTTOM&&Math::TouchEdge(this) != Direction::BR&&Math::TouchEdge(this) != Direction::BL)
		{
			this->Move({ 0,-10,0 });
			isMoveVertical = true;
		}
	}
	else
	{
		isMoveVertical = false;
	}
	//좌우
	if (isMoveVertical)
	{

		if (Keyboard::Get()->Press('A'))
		{
			if (Math::TouchEdge(this) != Direction::LEFT&&Math::TouchEdge(this) != Direction::TL&&Math::TouchEdge(this) != Direction::BL)
			{
				this->Move({ -(10 / (float)sqrt(2)),0,0 });
			}
		}
		else if (Keyboard::Get()->Press('D'))
		{
			if (Math::TouchEdge(this) != Direction::RIGHT&&Math::TouchEdge(this) != Direction::BR&&Math::TouchEdge(this) != Direction::TR)
			{
				this->Move({ (10 / (float)sqrt(2)),0,0 });
			}
		}
	}
	else
	{
		if (Keyboard::Get()->Press('A'))
		{
			if (Math::TouchEdge(this) != Direction::LEFT&&Math::TouchEdge(this) != Direction::TL&&Math::TouchEdge(this) != Direction::BL)
			{
				this->Move({ -10,0,0 });
			}
		}
		else if (Keyboard::Get()->Press('D'))
		{
			if (Math::TouchEdge(this) != Direction::RIGHT&&Math::TouchEdge(this) != Direction::BR&&Math::TouchEdge(this) != Direction::TR)
			{
				this->Move({ 10,0,0 });
			}
		}
	}
}

void Player::Move(D3DXVECTOR3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}

void Player::Update()
{
	PlayerCtrl();
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
