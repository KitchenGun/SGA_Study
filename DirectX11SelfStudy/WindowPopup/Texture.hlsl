struct VertexInput
{
	float4 position : POSITION0;//position == semantic(�������� ��ó�� ���ҿ� ���� �и��� �ǹ̸� �ο��ϱ����� Ű����) ���� ���ڴ� semantic�� �ε���
	float2 uv : TEXCOORD0;
};

struct PixelInput
{
	float4 position : SV_POSITION0;//SV = �ý��� value �� �߿��� ��
    float2 uv : TEXCOORD0;
};

cbuffer TransformBuffer : register(b0)//->0~13  16byte�� ����� �Ǿ���//4096*16���ϸ� ������
{
    matrix world;//matrix == float4X4
    matrix view;
    matrix proj;
};

PixelInput VS(VertexInput input)
{
	//1*4		4*4 -->1*4//��ġ ���͸� �ٸ��������� �̵��ϱ� ���ؼ��� ������ ��ġ�� �����ָ�ȴ�.
	//1,2,3,1 * 0000
	//			0000
	//			0000
	//			0000
	PixelInput output;
    output.position = mul(input.position,world);
    output.position = mul(output.position,view);
    output.position = mul(output.position, proj);
	
    output.uv = input.uv;

	return output;
}

Texture2D source_texture : register(t0);
SamplerState samp : register(s0);//sampling ������ �����͸� �����ϴ°�

float4 PS(PixelInput input) : SV_Target//���� ������ Ÿ�ٿ� �׷���
{
    float4 color = source_texture.Sample(samp, input.uv);
    //clip(color.a - 0.9f);//clip�Լ��� ���ڷ� �޴� �����Ͱ� 0���� ������ �����͸� �����
    if(color.a<0.1f)
    {
        discard;
    }
    return color;
}