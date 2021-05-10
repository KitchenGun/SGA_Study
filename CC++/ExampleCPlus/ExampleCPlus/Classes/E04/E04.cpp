#include "E04.h"

//#define E04_INHERITANCE	1
//#define E04_POLYMORPHISM	2
#define E04_PRACTICE		3

#if E04_PRACTICE

//#define PRACTICE_A	1;
#define PRACTICE_B	2;

#endif 
namespace E04Space
{
#if E04_INHERITANCE
	//�θ�Ŭ����
	class CParent
	{
	public:
		/*
		�θ�Ŭ������ �ڽ� Ŭ������ ���� �ٸ� �����̱� ������ ������ ������ ���ϴ� �Լ��� �����ϴ� ���� �����ϴ�
		�̶� �켱������ �ڽ� Ŭ������ ���� �Ǿ��ִ� �Լ��� �� ���� �켱������ ������
		���� �ڽ� Ŭ������ �Լ� ���ο��� �θ� Ŭ������ ������ �̸��� ���ϴ� �Լ��� ȣ���ϰ� �ʹٸ� :: ���� ���������ڸ� ����ϸ� �ȴ�
		*/
		//������ ����Ѵ�
		void PrintInfo()
		{
			printf("�θ�ü ����\n");
			printf("int : %d\n", m_nValue);
			printf("float : %f\n", m_fValue);
		}

	public:
		//������
		CParent(int a_nValue, float a_fValue)
			:
			m_nValue(a_nValue),
			m_fValue(a_fValue)
		{
			printf("Cparent(int,float)�θ�Ŭ���� ������ ȣ��\n");
		}
		//�Ҹ���
		~CParent(void)
		{
			printf("Cparent(int,float) �θ�Ŭ���� �Ҹ��� ȣ��\n");
		}
	protected:
		int m_nValue = 0;
		float m_fValue = 0.0f;
	};
	//�ڽ� Ŭ����
	class CChild : public CParent
	{
	public:
		//������ ���
		void PrintInfo()
		{
			CParent::PrintInfo();
			printf("\n�ڽİ�ü ����\n");
			printf("string : %s\n", m_szString);
		}
	public:
		/*
		Ŭ������ ��� �����϶� �������� �ùٸ� ȣ�� ������ �θ� Ŭ�������� �ڽ� ������ ȣ��Ǵ� ���̴�. ���� �θ� Ŭ������ �����ڸ� ȣ���ϴ� ������ �������� ���
		�����Ϸ��� ���ؼ� �ڵ����� �θ� Ŭ������ �⺻ �����ڸ� ȣ���ϴ� ������ �߰� �ȴ�.

		���� �θ� Ŭ������ �⺻ �����ڰ� �������� ���� ���
		�ݵ�� �ڽ� Ŭ������ �����ڸ� �ɹ� �̴ϼȶ����� ������ ���ؼ� �θ�Ŭ������ �����ڸ� ������� ȣ��������Ѵ�
		*/
		//������
		CChild(void) : CChild(0, 0.0f, "")//�θ�Ŭ���� ���� �־�� �ϱ⶧���� �̷��� �ڽ� ��ü���� ���� �ؾ��� ���� ������ ���
		{
			printf("Cchild(void)�ڽ�Ŭ���� ������ ȣ��\n");
		}
		CChild(int a_nValue, float a_fValue, const char *a_pszString)
			:
			CParent(a_nValue, a_fValue)
		{
			strcpy(m_szString, a_pszString);
			printf("Cchild(int,float,const char*)�ڽ�Ŭ���� ������ ȣ��\n");
		}
		/*
		Ư�� Ŭ���� ��� ���迡 ������ �Ҹ����� ȣ�� ������ �����ڿ� �޸� �ڽ� Ŭ�������� �θ� ������ ȣ��ȴ�
		*/
		//�Ҹ���
		~CChild(void)
		{
			printf("Cchild(void)�ڽ�Ŭ���� �Ҹ��� ȣ��\n");
		}
	private:
		char m_szString[100] = "";
	};
#elif E04_PRACTICE
#if PRACTICE_A
	//�迭
	class CArray
	{
	public:
		enum
		{
			DEF_SIZE = 5
		};
	public: //operator
		/*
		�̹� ������ �Ϸ�� ��ü�� �ٸ� ��ü�� ������ �����ϱ� ���ؼ��� �Ҵ� ������ �����ε� �̶�� �ϴ� Ư���� �ɹ� �Լ��� �����ؾ��Ѵ�

		�ش� �Լ� ���� �����Ϸ��� ���ؼ� �ڵ����� ��������� �Լ�
		�Ҵ翬���� �����ε��� �������� ���� ��� �����Ϸ��� �ڵ����� ���� ���縦 �����ϴ� �ش� �Լ��� �߰� �Ѵ�.
		*/
		CArray& operator=(const CArray &a_rOther)//��ü�� ������� �����ڸ� �����ְ� ����� �κ� 
		{
			SAFE_DELETE_ARRAY(m_pnValues);

			m_nSize = a_rOther.m_nSize;
			m_nNumValues = a_rOther.m_nNumValues;

			m_pnValues = new int[a_rOther.m_nSize];
			memcpy(m_pnValues, a_rOther.m_pnValues, sizeof(int)*a_rOther.m_nSize);

			/*
			c++ ��� �ɹ� �Լ����� �ش� �Լ��� ȣ���� ��ü�� ����Ű�� this �����Ͱ� ���� �ȴ�
			this �����ʹ� ���� �ش��Լ��� ȣ���� ��ü�� ����Ű�� �뵵�̸� �ش� �����Ͱ� �����ϱ� ������ �ɹ� �Լ����� �ɹ� ������ �����ϴ� ���� �����ϴ�
			->�� �����Ϳ��� ���� �����Ҷ� �ο���
			*/
			return *this;
		}

	public:
		/*
		c++Ŭ���� �ɹ��Լ��� const Ű���带 ����Ͽ� �ش��Լ���
		��� �ɹ� �Լ��� ���� �ϴ� ���� �����ϴ�

		��� �ɹ� �Լ���?
		�Լ� ���ο��� �ɹ� ������ �����Ҽ����� �Լ��� ��� �ɹ� �Լ���� �Ѵ�
		�� �ش� �Լ��� ��ü�� ����� ��� �����Ϸ����� �ش� �Լ� ���ο�����
		���� ������ �߻����� �ʴ´ٴ� ������ �ϱ� ���� �뵵�̴�.

		���� ��� ��ü�� �Ϲ����� �ɹ� �Լ��� ȣ�� �� �� ������ ��� �ɹ� �Լ��� ȣ���� �����ϴ�
		�̴� �Ϲ����� �ɹ��Լ� ������ �ɹ� ������ �����Կ� �־ �߻��ϴ� ���� ����� �����ϱ� ���Ѱ��̴�.
		*/
		//���� ������ ��ȯ
		int GetNumValues() const
		{
			return m_nNumValues;
		}
		//���� ��ȯ�Ѵ�
		int GetValue(int a_nIdx)const
		{
			return m_pnValues[a_nIdx];
		}
		//���� �����Ѵ�
		void SetValue(int a_nIdx, int a_nValue)
		{
			m_pnValues[a_nIdx] = a_nValue;
		}
		//���� �߰��Ѵ�
		void AddValue(int a_nValue)
		{
			//�迭�� ���� á�� ���
			if (m_nNumValues >= m_nSize)
			{
				m_nSize *= 2;
				m_pnValues = (int *)realloc(m_pnValues, sizeof(int)*m_nSize);
			}

			m_pnValues[m_nNumValues++] = a_nValue;
		}


	public://������ �Ҹ���
		/*
		c++�� �Լ��� �Ű� ������ ���� �� ��� �ش� �Ű� ������ �Է� �� ���� �Լ��� ȣ���ϴ� ���� �����ϴ�
		�� �ش� ������ ������ ������ �Լ��� �Է� ���� ���� ��� �ڵ����� �⺻���� ������ �� �ִ� ����Ʈ �Ű� ������ �����ϱ� �����̴�

		Ư�� �Լ��� �Է��� ���� ���� �ʾ��� ��� �ش� �Ű������� �Ҵ� ���� �����Ҽ��ִ� ����� �ǹ��Ѵ�.
		�Ϲ� �Ű������� ȥ�� ����� ���������� Ư�� �Ű� ������ ����Ʈ ���� �Ҵ�������쿡�� �ش� �Ű����� ���� ���ʹ� ����Ʈ ���� ���������Ѵ�.
		*/
		//CArray(int a_nParams1,int a_nSize = DEF_SIZE,int a_nParams2) �̰� ������ 
		CArray(int a_nSize = DEF_SIZE)
			:
			m_nSize(a_nSize)
		{
			m_pnValues = new int[a_nSize];
			memset(m_pnValues, 0, sizeof(int)*a_nSize);
		}
		//���� ������
		CArray(const CArray &a_rOther)
		{
			*this = a_rOther;
		}


		~CArray()
		{
			SAFE_DELETE_ARRAY(m_pnValues);

		}

	private://����
		int m_nSize;
		int m_nNumValues;

		int *m_pnValues = nullptr;
	};

	//�迭 ���
	void PrintArray(const CArray a_oArray)
	{
		for (int i = 0; i < a_oArray.GetNumValues(); ++i)
		{
			printf("%d ", a_oArray.GetValue(i));
		}
		printf("\n");
	}



#elif PRACTICE_B
enum class EMenu
{
	NONE = -1,
	ADD_TRIANGLE,
	ADD_RECTANGLE,
	ADD_LINE,
	DRAW_SHAPES,
	EXIT,
	MAX_VALUE

};

enum class EColor
{
	NONE = -1,
	RED,
	GREEN,
	BLUE,
	MAX_VALUE
};

class CShape
{
public:
	//���� ��ȯ
	const char* GetColorStr(void)const
	{
		static const char*apszColorStrs[] = {
		"������",
		"���",
		"�Ķ���"
		};

		return apszColorStrs[(int)m_eColor];
	}
	/*
	c++���� mutable Ű���带 �ɹ� ���� �տ� ��������� �� �ش� ������ ��� �ɹ� �Լ� ���ο��� ������ �����ϴ�
	const cast �� ���������� mutable Ű����� ������� �ʴ� ���� ���� �����̴�. 
	*/
	//������ �׸���
	virtual void DrawShape(void)= 0;
protected://������
	/*
	c++Ŭ������ �����ڸ� public ������ �ƴ� �ٸ� ��ȣ �������� ������� ��� 
	�̴� ��ü�� �����Ҽ��ִ� ������ ���� ��Ű�� ���� �ǹ��Ѵ�
	�� protected  ������ ��� �ش� �����ڴ� �ڽ� Ŭ���� �Ǵ� ���ο����� ȣ�� �����ϱ� ������ �̴� �� �ܺο��� 
	�ش� ��ü�� ���������� �����ϴ� ���� �Ұ��� �ϴٴ� ���� �ǹ��Ѵ�
	*/
	CShape(const EColor a_eColor)
	:
	m_eColor(a_eColor)
	{
		//do nothing
	}
protected:
	mutable EColor m_eColor = EColor::NONE;
};
/*
c++���� Ŭ���� ��ӽ� �ش� Ŭ������ ��� ������ ����ϴ� ���� �����ϴ�
�̴� �θ� Ŭ������ �ּ� ���� ������ ����ϴ� ������ �� ���� protected�� ����� �õ��� ��� 
�θ� Ŭ������ private �� protected ������ �״�� ����� ������ public ������ protected�� ������ �Ǿ ����� �ȴ�
(public �ܷ̿� ��� �õ��� �θ�Ŭ������ �ɹ��� �ܺο��� ���� �Ұ��� �ϴ�)
*/
class CTriangle :public CShape
{
public:
	//������ �׸���
	virtual void DrawShape()override
	{
		const char *pszColorStr = this->GetColorStr();
		printf("%s �ﰢ���� �׸���\n",pszColorStr);
	}

public:
	//������
	CTriangle(const EColor a_eColor)
	:
	CShape(a_eColor)
	{
		//do nothing
	}
};

class CRectangle :public CShape
{
public:
	//������ �׸���
	virtual void DrawShape()override
	{
		const char *pszColorStr = this->GetColorStr();
		printf("%s �簢���� �׸���\n", pszColorStr);
	}

public:
	//������
	CRectangle(const EColor a_eColor)
	:
	CShape(a_eColor)
	{
		//do nothing
	}
};

class CLine :public CShape
{
public:
	//������ �׸���
	virtual void DrawShape()override
	{
		const char *pszColorStr = this->GetColorStr();
		printf("%s ���� �׸���\n", pszColorStr);
	}

public:
	//������
	CLine(const EColor a_eColor)
		:
		CShape(a_eColor)
	{
		//do nothing
	}
};

class CCanvas
{
public://�Լ�
	void AddShape(std::shared_ptr<CShape> a_oShapePtr)
	{
		m_oShapeList.push_back(a_oShapePtr);
	}
	//���� �׸���
	void DrawShapes(void)
	{
		for (int i = 0; i < m_oShapeList.size(); ++i)
		{
			m_oShapeList[i]->DrawShape();
		}
	}
public://�Ҹ���
	virtual ~CCanvas(void)
	{
		//for (int i = 0; i < m_nNumShapes; ++i)
		//{
		//	SAFE_DELETE(m_apShapes[i]);
		//}
	}
private:
	//����
	int m_nNumShapes = 0;
	std::vector<std::shared_ptr<CShape>> m_oShapeList;
	//CShape *m_apShapes[100];
};

CShape *CreateShape(EMenu a_eMenu)
{
	/*
	uniform int distribution ��ü�� �ִ� ���� ������ �ش� ������ ������ �����Ѵ� �� �ּ� 0 ~ �ִ� 2 ��� ��� ���� ���� ������ 0~3���� �̴�
	*/
	std::random_device oRandom;
	std::uniform_int_distribution<int> oUniform((int)EColor::RED,(int)EColor::BLUE);

	EColor eColor = static_cast<EColor>(oUniform(oRandom));
	switch (a_eMenu)
	{
	case EMenu::ADD_TRIANGLE: 
		return new CTriangle(eColor); break;
	case EMenu::ADD_RECTANGLE: 
		return new CRectangle(eColor); break;
	case EMenu::ADD_LINE:
		return new CLine(eColor); break;
	}
}
#endif
#elif E04_POLYMORPHISM
	//�θ�Ŭ����
	class CParent
	{
	public:

		/*
		�ɹ� �Լ��� virtual Ű���带 ����ϸ� �ش��Լ��� �����Լ��� �ȴ�.
		�����Լ��� ?
		Ư�� Ŭ������ �θ� �ڽ� ���踦 �����ϰ� ������ ���� �θ� Ŭ������ Ư�� �Լ��� �ڽ� Ŭ�������� �����ϰ� �������� ���
		�θ� Ŭ������ �Լ��� �ƴ϶� �ڽ� Ŭ������ �Լ��� ȣ�� �ϵ��� ���ִ� �ɹ� �Լ��� �ǹ��Ѵ�
		���� ��ó�� �θ� Ŭ������ �Լ� ��� �ڽ� Ŭ������ �Լ��� ȣ��Ǵ� ������ �������̵� ������ �����Ǿ��ٰ� �Ѵ�.

		�� �ڽ� Ŭ������ �Լ��� �������̵� ������ �����ϱ� ���ؼ��� �ݵ�� �θ� Ŭ������ �����ϴ� �ɹ��Լ��� ������ ��ġ�ؾ��Ѵ�
		�Լ� �ڿ� ovveride�� ���̸� ������ ����ش�

		c++��� �������̵� ���� ���� 
		:
		c++Ư�� Ŭ������ �����Լ��� �ϳ��� �����Ұ�� �����Ϸ��� �Լ� �����ͷ� �̷���� �����Լ� ���̺��� �����ϰ� 
		�ش� ���̺��� ����Ű�� �����Ͱ� �ڵ����� Ŭ������ �߰� �ȴ�
		���� ���� �Լ� ���̺� �����ϴ� �ɹ� �Լ��� ȣ���� ��� 
		�ش� �Լ��� ���������� ȣ�� �Ǵ� ���� �ƴ϶� ���� �Լ� ���̺� �����ؼ�
		�ش� ���̺� �����ϴ� �Լ� �����Ͱ� ����Ű�� �ɹ� �Լ��� ȣ��ȴ�
		�� ���� �Լ� ���̺��� �����Ϸ��� ���ؼ� �ڵ����� �ش� Ŭ������ �߰��Ǳ� ������ 
		�����Լ��� �ϳ��� ���ϰ� �ִ� ��ü�� ����� memset���� �ʱ�ȭ �õ��ϸ� �ȵȴ�
		*/
		//������ ����Ѵ�
		virtual void ShowInfo()
		{
			printf("CParent.ShowInfo()ȣ��\n");
		}
	public:
		/*
		�Ϲ������� �������� ������ �θ� Ŭ������ �����ͷ� �������� ���
		�ڽ� Ŭ������ �Ҹ��ڰ� ȣ�� ���� �ʴ� ������ �߻��Ѵ� ���� �ش� ������ �ذ��ϱ� ���ؼ��� 
		�ݵ�� �θ� Ŭ������ �Ҹ��ڿ� virtual Ű���带 ����Ͽ�
		�ش� �Ҹ��ڸ� ��� �Ҹ��ڷ� ����������Ѵ�

		�� Ư�� Ŭ������ �Ҹ��ڰ� ���� �Ҹ��ڰ� �ƴ϶�� �̴� �ش� Ŭ������ ����� ������� ����� ���� �Ϲ����� �����̴�.
		*/
		virtual ~CParent()//���� �Ҹ��� 
		{
			printf("�θ� �Ҹ��� ȣ��\n");
		}
	};
	//�ڽ�Ŭ����
	class CChild:public CParent
	{
	public:
		/*
		�ڽ� Ŭ�������� �θ�Ŭ������ ������ ������ ���� �����Լ� ���������� 
		�ش� �Լ� ���� �����Ϸ��� ���ؼ� �ڵ����� ���� �Լ��� ���� �ȴ�
		�����Լ��� ������ ������ ���� �Լ��� �ڽĿ� �������� ��� virtual Ű���带 ������ִ� ���� ���� �����̴�.
		c++11���������� override ��� Ű���带 �������ֱ� ������ �θ� Ŭ������ �ɹ��Ը� �߸��� �������� �ڽ� Ŭ������ �������̵� ���� ���
		�����Ϸ��� ���ؼ� �����߻��� ���� �ϴ� �� ������ �����ϴ� ���� �����ϴ�. 
		
		c++11 �̻� ���ʹ� final Ű���带 ���ؼ� �ش� �ɹ� �Լ��� �ڽ� Ŭ���� ���� ���̻� �������̵尡 �Ұ��� �ϵ��� ���ƹ����� ���� �����ϴ� �� Ŭ����
		�����Կ� �־ �θ� Ŭ������ Ư�� �ɹ��Լ����ݵ�� ȣ�� �ؾ��� ��� �ش� Ű���带 ��������ν� �ڽ� Ŭ�������� �������̵� ��Ű�� �Ǽ����� �����ϴ�

		*/
		//������ ����Ѵ�
		virtual void ShowInfo() final override
		{
			this->DoShowInfo();
			printf("CChild.ShowInfo()ȣ��\n");
		}

	protected:
		//���� �����Լ�
		/*
		���� �Լ��� 0 ��ȣ�� ��������ν� �ش� �Լ��� ���� �����Լ��� �����ϴ� ���� �����ϴ�
		���� �����Լ���?
		�Լ��� �����θ� ���ϰ� ���� ���� �����Լ��� �ǹ��ϸ� Ư�� Ŭ������ ���� ���� �Լ��� �ϳ��� �����Ұ�� �ش� Ŭ������ ��üȭ ��ų������ �߻� Ŭ������ �ȴ�
		�� Ư�� Ŭ������ ���ؼ� ��ü�� �����ϱ� ���ؼ��� �ش� ��ü�� ���� �Ӽ��� ������ �������־���ϱ� ������ 
		���� �����Լ��� ���ϰ� �ִٴ� ���� �ش� ������ ���� ������ ���ٴ� ���� �ǹ��ϸ� �̴� �� ��ü�� �����ϱ����� ������ �Ҿ����ϴٴ� ���� �ǹ��Ѵ�
		���� �����Լ��� ���ϰ� �ִ� �߻� Ŭ������ ���������� ��üȭ ��ų���� ������ �ڽ� Ŭ�������� �ش� Ŭ������ ��������� ��üȭ�� �����ϴ� 
		�� �̰�� �ڽ�Ŭ�������� �ݵ�� �θ�Ŭ������ �����ϴ� ���� ���� �Լ��� ��� �������̵� �� ��������� �Ѵ�
		���� �������̵� ���� ���� ��� ��üȭ ��ų������ �߻��Լ� Ŭ������ �ȴ�

		�̰� ����ϸ� �������̽��� �䳻�����ִ�.
		*/
		virtual void DoShowInfo() = 0; 
	public:
		virtual ~CChild()
		{
			printf("�ڽ� �Ҹ��� ȣ��\n");
		}
	};
	//���� �ڽ� Ŭ����
	class CSubChild : public CChild
	{
	public:
		//�� ��ȯ �Ѵ�
		int GetValue(void)
		{
			return m_nValue;
		}

		//��� �ɹ� �Լ�
		/*
		const cast ����ȯ �����ڸ� ����ϸ� ������� �Ͻ������� �����ϴ� ���� �����ϴ� 
		���� ����ɹ� �Լ� ���ζ� �ϴ��� �ش� �����ڸ� ����ϸ� �ɹ� ������ ���� �����ϴ� ���� �����ϴ�
		�� const cast�� ������ ���� ���ʶ߸��� ������ �����ϱ� ������ �����ϸ� ������� �ʴ� ���� ���� �����̴�
		(������ �����)
		*/
		void ConstMemFunc(void)const
		{//const cast
			const_cast<CSubChild*>(this)->m_nValue = 10;
		}
	protected:

		virtual void DoShowInfo() override
		{
			printf("CSubChild.DoShowInfo()ȣ��\n");
		}

	private:
		int m_nValue = 0;
	public: //�Ҹ���
	virtual ~CSubChild()
	{
		printf("���� �ڽ� �Ҹ��� ȣ��\n");
	}
	};

#endif // E04_INHERITANCE

	void E04(const int argc, const char ** args)
	{
#if E04_INHERITANCE
		CChild oChild;
		oChild.PrintInfo();

#elif E04_PRACTICE
#if  PRACTICE_A
		CArray oArrayA;

		for (int i = 0; i < 10; ++i)
		{
			oArrayA.AddValue(i + 1);
		}

		CArray oArrayB(oArrayA);
		CArray oArrayC;

		oArrayC = oArrayA;

		printf("\narray a\n");
		PrintArray(oArrayA);
		printf("\narray b\n");
		PrintArray(oArrayA);
		printf("\narray c\n");
		PrintArray(oArrayA);

#elif PRACTICE_B
		EMenu eMenu = EMenu::NONE;
		CCanvas oCanvas;
		do
		{
			printf("\n�޴�\n");
			printf("1.�ﰢ�� �߰�\n");
			printf("2.�簢�� �߰�\n");
			printf("3.�� �߰�\n");
			printf("4.���� �׸���\n");
			printf("5.����\n");
			printf("\n �޴� ���� : ");
			scanf("%d", &eMenu);

			eMenu = static_cast<EMenu>((int)eMenu - 1);

			switch (eMenu)
			{
			case EMenu::ADD_TRIANGLE:
			case EMenu::ADD_RECTANGLE:
			case EMenu::ADD_LINE:
			{
				CShape *pShape = CreateShape(eMenu);
				oCanvas.AddShape(std::shared_ptr<CShape>(pShape));
				break;
			}
			case EMenu::DRAW_SHAPES:
			{
				oCanvas.DrawShapes();
				break;
			}
			case EMenu::EXIT:
			{
				break;
			}
			default:
				break;
			}

		} while (eMenu != EMenu::EXIT);

#endif //PRACTICE_A
#elif E04_POLYMORPHISM
		/*
		�θ� Ŭ������ �����ͷ� �ڽ� ��ü�� ����Ű�� ���� �������� �ݴ�� �ڽ� Ŭ������ �����ͷ� �θ� ��ü�� ����Ű�� ���� �Ұ��� �ϴ�
		*/
		CParent *pParentA = new CParent();
		CParent *pParentB = new CSubChild();
		/*
		c++ ����ȯ �������� ����
		//����ȯ �����ڵ��� �д� ����� ��� �ٲٴ� ���̴� �̰� �����Ϳ� �������� ������ ���� ���·� ���ư���
		static_cast			�ҿ����� �ٿ� ĳ���� ����  (���� c�� ����ȯ�� ������ ����)å���� ����ڿ���
		dynamic_cast		������ �ٿ�ĳ���� ����
		const_cast			��ü�� ����� ���� ����  ����� ���Ŵ� ������ ����
		reinterpert_cast	����<->�ּҰ��� ����ȯ

		*/
		CChild *pChildA = new CSubChild;
		CChild *pChildB = dynamic_cast<CChild*>(pParentB);
		/*
		dynamic cast �� ��ȯ �����ڿ� ���ؼ� �ٿ� ĳ������ �Ұ��� �Ұ�� null �����Ͱ� ��ȯ �ȴٴ� ���� �˼��ִ�
		�ش� �����ڴ� ������ �ٿ� ĳ������ �����ϱ� ���ؼ� ���������� �������� �˻��ϴ� �ڵ���� �ڵ����� �߰��Ǳ� ������
		�̴� �� �����ս� ���ϸ� ���߽�ų�� �ִ�.

		�� dynamic cast ����ȯ �����ڸ� ����Ҷ� �����Լ��� �������� ������ ����Ҽ�����
		�̴� ĳ���� ���� ���θ� �����Լ� ���̺��� ������� �񱳸� �õ��ϱ� ������ �����Լ� ���̺��� ���ٸ� �ش� �����ڸ� ����ϴ� ���� �Ұ����ϴ�

		*/
		//�ڽ� Ŭ���� ����ȯ �����Ұ��
		if (pChildB != NULL)
		{
			printf("�θ�->�ڽ� �� ��ȯ ����\n");
		}

		//child Ŭ������ �߻� Ŭ�����̱� ������ new Ű���带 ���ؼ� ��ü�� �����ϴ� ���� �Ұ����ϴ�
		//CChild *pChildB = new CChild;
		//CChild *pChildB = new CParent;

		pParentA->ShowInfo();
		printf("\n");
		pParentB->ShowInfo();
		printf("\n");
		pChildA->ShowInfo();
		printf("\n");
		printf("\n==========��� �ɹ� �Լ� ȣ��=========\n");
		static_cast<CSubChild*>(pChildA)->ConstMemFunc();
		printf("Value : %d\n\n", static_cast<CSubChild*>(pChildA)->GetValue());

		//pChildB->ShowInfo();
		SAFE_DELETE(pParentA);
		printf("\n");
		SAFE_DELETE(pChildA);
		printf("\n");
		SAFE_DELETE(pParentB);//�ڽ��� �־ �ڽļҸ��� ȣ��ȵ� virtual�� �ذ�
		printf("\n");
		//SAFE_DELETE(pChildB);

#endif // E04_INHERITANCE
	}
}
