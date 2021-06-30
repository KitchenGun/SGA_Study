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


cbuffer World : register(b0)
{
    matrix _world;
};

cbuffer ViewProjection : register(b1) //��� ���۸� ������
{
    matrix _view;
    matrix _proj;
};

cbuffer Selection : register(b0)
{
	int _selection;
};



	PixelInput VS(
	VertexInput input)//�Է� pos�� �Է� color �� �״�� PixelInput ���·� ��ȯ
{
	PixelInput output;
    //���Ϳ� ����� ���� �����Ұ�
    output.position = mul(input.position, _world);//world �������� ��ȯ
    output.position = mul(output.position, _view);//view �������� ��ȭ
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
	
	if (_selection == 1)
	{
		result = srcTex0.Sample(samp, input.uv);
	}
	else if (_selection == 2)//�¿� �ſ�
	{
		float4 l = srcTex0.Sample(samp, input.uv);
		float4 r = srcTex0.Sample(samp, float2(input.uv.x - 0.5f, input.uv.y));
		
		if (input.uv.x < 0.5f)
			result = l;
		if (input.uv.x > 0.5f)
			result = r;
		
		if (input.uv.x > 0.499f && input.uv.x < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
	}
	else if (_selection == 3)//4�и� �ſ�
	{
		float4 site1 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y));
		float4 site2 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y));
		float4 site3 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y - 0.5f));
		float4 site4 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y - 0.5f));
		
		if (input.uv.x < 0.5f && input.uv.y < 0.5f)
			result = site1;
		if (input.uv.x > 0.5f && input.uv.y < 0.5f)
			result = site2;
		if (input.uv.x < 0.5f && input.uv.y > 0.5f)
			result = site3;
		if (input.uv.x > 0.5f && input.uv.y > 0.5f)
			result = site4;
		
		if (input.uv.x > 0.499f && input.uv.x < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
		if (input.uv.y > 0.499f && input.uv.y < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
	}
	else if (_selection == 4)//4�и� ���� �ſ�
	{
		float4 site1 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y));
		float4 site2 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y));
		float4 site3 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y - 0.5f));
		float4 site4 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y - 0.5f));
		
		if (input.uv.x < 0.5f && input.uv.y < 0.5f)
			result = site1;
		if (input.uv.x > 0.5f && input.uv.y < 0.5f)
			result = site2;
		if (input.uv.x < 0.5f && input.uv.y > 0.5f)
			result = site3;
		if (input.uv.x > 0.5f && input.uv.y > 0.5f)
			result = site4;
		
		if (input.uv.x > 0.499f && input.uv.x < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
		if (input.uv.y > 0.499f && input.uv.y < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
	}
	return result;
}