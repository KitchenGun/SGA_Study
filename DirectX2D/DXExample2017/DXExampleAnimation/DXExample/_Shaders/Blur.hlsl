#include "CBuffers.hlsl"

//glsl���� ���̴� ���� �Լ����� Ư���Լ��� ���������� ����Ҽ��ִ� Ư¡�� �ִ�
struct VertexInput//pos �� �������
{
	float4 position : POSITION0;
	//Semantics�̶�?	
	//����ڰ� ���Ƿ� �����ϴ� ���������� ���ؽ� ���̴��� �Է� ����ü�� �������� � �ڷ�� ������� �˷��ִ� ���� �ø�ƽ�̴�
	float2 uv : TEXCOORD0;
};
struct PixelInput
{
	float4 position : SV_POSITION0;//sv_ system value�� ���ڷ� Ư���� �ǹ̸� ���� Semantics name���� ����
    float2 uv : TEXCOORD0;
};



PixelInput VS(VertexInput input)//�Է� pos�� �Է� color �� �״�� PixelInput ���·� ��ȯ
{
	PixelInput output;
    //���Ϳ� ����� ���� �����Ұ�
	output.position = mul(input.position, _world); //world �������� ��ȯ
	output.position = mul(output.position, _view); //view �������� ��ȭ
	output.position = mul(output.position, _proj); //projection ������ ��ȯ
    
    //�������� ������ ����� �ƴ� �Ϲ������� ����ϴ� ���
	output.uv = input.uv;
    
	return output;
}

Texture2D srcTex0 : register(t0);

SamplerState samp : register(s0);

float4 PS(PixelInput input) : SV_Target //���� ������ Ÿ�ٿ� �׷���
{
	float4 result = 0;
	float4 color = srcTex0.Sample(samp, input.uv);//����
	
	float2 arr[8] =
	{
		float2(-1, -1), float2(0, -1), float2(1, -1),
		float2(-1, 0),				   float2(1, 0),
		float2(-1, 1), float2(0, 1),   float2(1, 1)
	};
	
	
	[flatten]//0,1 ���̰����� ��ǥ�� ���� //blur�� ������ ���� //input ����� ����� ������ ����� �����  
	if (input.uv.x > _localRect.x / _textureSize.x &&
		input.uv.x < _localRect.z / _textureSize.x &&
		input.uv.y > _localRect.y / _textureSize.y &&
		input.uv.y < _localRect.w / _textureSize.y)
	{
		//blur������ ���� �ȼ����� �Ÿ��� �ǹ���
		/*
			�� blur�� 8�� ��� 8��ŭ �Ÿ��� ������ ����� ����.
		*/
		for (int blur = 0; blur < _count; blur++)//�ѹ� �������� blur ó����
		{
			for (int i = 0; i < 8; i++)
			{
				//�迭������ ���� �ȼ��� ������ ����� ���� ���� �ٿ���ø��ϴ� ����
				float x = arr[i].x * (float) blur / _textureSize.x;//����ȭ�۾����� ��ǥ�� ����
				float y = arr[i].y * (float) blur / _textureSize.y;
				//��� �ȼ����� �ֺ����� �̵�
				float2 uv = input.uv + float2(x, y);
				//�̵��κ� �ȼ� ��ȯ������ ����
				color += srcTex0.Sample(samp, uv);//�ȼ���ŭ �̵��� uv�� ������ ������ �����ش�
			}
		}
		//�ڱ� �ڽ��� ������ 9���� ������ �� ����� �ִ´�
		color /= _count * 8 + 1;
		result = float4(color.rgb, 1);

	}
	else
	{
		result = color;
	}
	
	if (_bOutline && (input.uv.x < 0.01f || input.uv.x > 0.99f || input.uv.y < 0.01f || input.uv.y > 0.99f))//����
	{
		result = float4(1, 1, 1, 1);
	}
	return result;
}
