#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define INT_MAX 1000000000


struct Pizza 
{
	string name;
	int price_S;
	int price_M;
	int price_L;
};
struct OrderItem 
{
	string name;
	string size;
	int quantity;
};
//���� ũ�Ⱑ ū�� ���� �������� ����
bool cmp(OrderItem& v1, OrderItem& v2) {

	int value1 = 0 , value2 = 0;
	//�Ǵ� ���� ����
	if(v1.size == "Large")
		value1 = 3;
	else if(v1.size == "Medium")
		value1 = 2;
	else
		value1 = 1;

	if(v2.size == "Large")
		value2 = 3;
	else if(v2.size == "Medium")
		value2 = 2;
	else
		value2 = 1;
	//�Ǵ�
	if(value1>value2)
		return true;
	else
		return false;
}


int solution(vector<Pizza>& menu, vector<OrderItem>& order) 
{
	//���� ����
	int totalPizzaCount =0;
	//���
	vector<int> result = { 0,0,0,0,0 }; //1,2,3,4 ���� 5�� ����X
	
	//������ ����
	map<string,int> pizzaType;
	sort(order.begin(), order.end(), cmp);
	for (OrderItem item : order)
	{
		//�� ���� ����
		totalPizzaCount+=item.quantity;
		if(pizzaType.count(item.name))
			pizzaType[item.name] += item.quantity;
		else
			pizzaType.insert({ item.name,item.quantity });
		//�� ���� ���
		for (Pizza target : menu)
		{
			if (target.name == item.name)
			{
				if (item.size == "Small")
				{
					result[0] += target.price_S * item.quantity;
					
				}
				else if (item.size == "Medium")
				{
					result[0] += target.price_M * item.quantity;
				}
				else
				{
					result[0] += target.price_L * item.quantity;
				}
			}
		}
	}
	//result ����
	for (int i = 0; i < 5; i++)
	{
		result[i] = result[0];
	}
	//���� 1��
	if (totalPizzaCount >= 3)
	{
		int cheap = INT_MAX;
		//���� �� ���� ã��
		for (int i =0;i<(int)order.size();i++)
		{
			for (Pizza target : menu)
			{
				if (target.name == order[i].name)
				{
					if (order[i].size == "Small")
					{
						result[0] += target.price_S * order[i].quantity;
						cheap = min(cheap, target.price_S);
					}
					else if (order[i].size == "Medium")
					{
						result[0] += target.price_M * order[i].quantity;
						cheap = min(cheap, target.price_M);
					}
					else
					{
						result[0] += target.price_L * order[i].quantity;
						cheap = min(cheap, target.price_L);
					}
				}
			}
		}
		result[0] -= cheap;
	}
	//���� 2��
	int Discount = 0;
	for (auto target : pizzaType)
	{
		if (target.second >= 5)//5�� �̻� �ֹ�
		{
			int count =0;
			for (OrderItem item : order)
			{
				if (target.first == item.name)
				{
					if(count+item.quantity<=5)//
					{
						count += item.quantity;
						for (Pizza pizza : menu)//������ ���� ���ݸ�ŭ üũ
						{
							if (pizza.name == item.name)
							{
								if (item.size == "Small")
								{
									Discount += pizza.price_S * item.quantity;
								}
								else if (item.size == "Medium")
								{
									Discount += pizza.price_M * item.quantity;
								}
								else
								{
									Discount += pizza.price_L * item.quantity;
								}
							}
						}
					}

					
				}
			}
		}
	}
	result[1] -= Discount;
	result[1] += 100;

	//���� 3��

	//���� 4��
		

	//���� ���
	int answer = INT_MAX;
	for(int temp : result)
	{
		if(temp<=answer&&temp!=0)
			answer = temp;	
	}

	return answer;
}

int main()
{
	vector<Pizza> menu =
	{
		{"margherita", 90, 80, 100},
		{"hawaii", 80, 90, 120},
		{"capricciosa", 50, 70, 130},
		{"greek", 50, 70, 130}
	};
	vector<OrderItem> order =
	{
		{"greek", "Small", 5},
		{"margherita", "Small", 4},
		{"hawaii", "Large", 1},
		{"margherita", "Medium", 2},
		{"capricciosa", "Small", 7}
	};

	std::cout<<solution(menu, order)<<endl;
}