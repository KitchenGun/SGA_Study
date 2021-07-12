/////////////////vertex shader �κ�
cbuffer World : register(b0)
{
    matrix _world;
};

cbuffer ViewProjection : register(b1) //��� ���۸� ������
{
    matrix _view;
    matrix _proj;
};

/////////////////pixel shader �κ�
cbuffer SelectBuffer : register(b0)//ȿ�� ���ð� ȭ�� ũ��(������ blur�� hlsl�� ȣ���� ��ü�� �����)
{
	int _selection;
	float2 _textureSize;
	bool _bOutline;
};

cbuffer BlurBuffer : register(b1)//blur ���� 
{
	uint _count;
};

cbuffer LocalBuffer : register(b2)//blur ó���� ���� ����
{
	float4 _localRect;
};

