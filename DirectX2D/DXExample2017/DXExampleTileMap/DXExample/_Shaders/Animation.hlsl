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
	//����Ÿ�� �����°� //r255 g0 b255
	//���� �κ� �� �����°� //r g b  a 1
	//if (color.a < 0.1f)// blendState�� ����Ͽ��� �ϴ� ��
	//	discard;
	
	return color;

}
