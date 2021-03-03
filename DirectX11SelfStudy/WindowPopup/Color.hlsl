struct VertexInput
{
	float4 position : POSITION0;//position == semantic(�������� ��ó�� ���ҿ� ���� �и��� �ǹ̸� �ο��ϱ����� Ű����) ���� ���ڴ� semantic�� �ε���
	float4 color : COLOR0;
};

struct PixelInput
{
	float4 position : SV_POSITION0;//SV = �ý��� value �� �߿��� ��
	float4 color : COLOR0;
};

PixelInput VS(VertexInput input)
{
	PixelInput output;
	output.position = input.position;
	output.color = input.color;

	return output;
}

float4 PS(PixelInput input) : SV_Target//���� ������ Ÿ�ٿ� �׷���
{
    return input.color;
}