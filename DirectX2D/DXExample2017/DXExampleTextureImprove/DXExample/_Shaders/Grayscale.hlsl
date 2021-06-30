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

cbuffer Selection : register(b0) //ps ���� �̴� 
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
	float4 color = srcTex0.Sample(samp, input.uv);
	float3 grayscale = 0;
	if (_selection == 1)
	{
		
	}
	else if (_selection == 2)//�߸�
	{
		grayscale = (color.r + color.g + color.b) / 3.0f;
		color = float4(grayscale.xyz,1);
	}
	else if (_selection == 3)//����
	{
		grayscale = 0.299f * color.r + 0.587f * color.g + 0.114f * color.b;
		color = float4(grayscale.xyz, 1);//color���� �����Ͽ��� ����
	}
	else if (_selection == 4)//���Ǿ�
	{
		color.r = dot(color.rgb, float3(0.393f,0.769f,0.189f));
		color.g = dot(color.rgb, float3(0.349f, 0.686f, 0.168f));
		color.b = dot(color.rgb, float3(0.272f, 0.534f, 0.131f));
		//color���� �����Ͽ��� ����
	}
	return color;
}   
