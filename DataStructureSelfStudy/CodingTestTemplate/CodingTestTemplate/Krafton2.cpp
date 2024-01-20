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
//피자 크기가 큰거 먼저 나오도록 정렬
bool cmp(OrderItem& v1, OrderItem& v2) {

	int value1 = 0 , value2 = 0;
	//판단 기준 설정
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
	//판단
	if(value1>value2)
		return true;
	else
		return false;
}


int solution(vector<Pizza>& menu, vector<OrderItem>& order) 
{
	//피자 개수
	int totalPizzaCount =0;
	//결과
	vector<int> result = { 0,0,0,0,0 }; //1,2,3,4 할인 5번 할인X
	
	//데이터 정리
	map<string,int> pizzaType;
	sort(order.begin(), order.end(), cmp);
	for (OrderItem item : order)
	{
		//총 피자 개수
		totalPizzaCount+=item.quantity;
		if(pizzaType.count(item.name))
			pizzaType[item.name] += item.quantity;
		else
			pizzaType.insert({ item.name,item.quantity });
		//총 가격 계산
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
	//result 복사
	for (int i = 0; i < 5; i++)
	{
		result[i] = result[0];
	}
	//할인 1번
	if (totalPizzaCount >= 3)
	{
		int cheap = INT_MAX;
		//가장 싼 피자 찾기
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
	//할인 2번
	int Discount = 0;
	for (auto target : pizzaType)
	{
		if (target.second >= 5)//5개 이상 주문
		{
			int count =0;
			for (OrderItem item : order)
			{
				if (target.first == item.name)
				{
					if(count+item.quantity<=5)//
					{
						count += item.quantity;
						for (Pizza pizza : menu)//빠지는 피자 가격만큼 체크
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

	//할인 3번

	//할인 4번
		

	//정답 출력
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