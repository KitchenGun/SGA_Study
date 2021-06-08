//glsl���� ���̴� ���� �Լ����� Ư���Լ��� ���������� ����Ҽ��ִ� Ư¡�� �ִ�
struct VertexInput//pos �� �������
{
	float4 position : POSITION0;
	//Semantics�̶�?	
	//����ڰ� ���Ƿ� �����ϴ� ���������� ���ؽ� ���̴��� �Է� ����ü�� �������� � �ڷ�� ������� �˷��ִ� ���� �ø�ƽ�̴�
	float2 uv : TEXCOORD0;//�ؽ����� ����
};
struct PixelInput
{
	float4 position : SV_POSITION0;//sv_ system value�� ���ڷ� Ư���� �ǹ̸� ���� Semantics name���� ����
    float2 uv : TEXCOORD0;
};

cbuffer TransformBuffer : register(b0)  //��� ���۸� ������
{
    matrix _world;
    matrix _view;
    matrix _proj;
}

PixelInput VS(VertexInput input)//�Է� pos�� �Է� color �� �״�� PixelInput ���·� ��ȯ
{
    PixelInput output;
    //���Ϳ� ����� ���� �����Ұ�
    output.position = mul(input.position, _world);//world �������� ��ȯ
    output.position = mul(output.position, _view);//view �������� ��ȭ
    output.position = mul(output.position, _proj); //projection ������ ��ȯ
    output.uv = input.uv;
    
    return output;
}

Texture2D sourceTex : register(t0); //sourceTex texture 2d ���·� ����

SamplerState samp : register(s0); // samp��Ŀ� ������ ����

float4 PS(PixelInput input) : SV_Target //���� ������ Ÿ�ٿ� �׷���
{
    float4 color = sourceTex.Sample(samp, input.uv);//�ҽ����Ϸ� ���� ���ø� ������ �°� uv�� ���� ���缭 �����Ѵ� 
    return color;
}
