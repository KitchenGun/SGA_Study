//glsl���� ���̴� ���� �Լ����� Ư���Լ��� ���������� ����Ҽ��ִ� Ư¡�� �ִ�
struct VertexInput//pos �� �������
{
	float4 position : POSITION0;
	//Semantics�̶�?	
	//����ڰ� ���Ƿ� �����ϴ� ���������� ���ؽ� ���̴��� �Է� ����ü�� �������� � �ڷ�� ������� �˷��ִ� ���� �ø�ƽ�̴�
	float4 color : COLOR0;
};
struct PixelInput
{
	float4 position : SV_POSITION0;//sv_ system value�� ���ڷ� Ư���� �ǹ̸� ���� Semantics name���� ����
	float4 color : COLOR0;
};
cbuffer World : register(b0)
{
    matrix _world;
}

cbuffer ViewProjection : register(b1)  //��� ���۸� ������
{
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
    output.color = input.color;
    
    return output;
}


float4 PS(PixelInput input) : SV_Target //���� ������ Ÿ�ٿ� �׷���
{
    return input.color;
}
