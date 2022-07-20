#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int v, n;
	cin>>v>>n;

	const int size = v+1;

	vector<vector<int>> graph(size);	//������ ���������� ������ ����
	vector<int> indegree(size,0);	//������ indegree(����)�� ������ ����
	int a, b;
	for (int i = 0; i < n; i++) {
		cin>>a>>b;
		graph[a].push_back(b);	//����
		indegree[b]++;	//�����ø�
	}

	priority_queue <int, vector<int>, greater<int> > q;
	queue <int> printQ;	//��¿� ť
	vector<bool> visit(size,false);	//�湮üũ, ����Ŭ ���翩���Ǵ�

	//ó�� ������ 0������ ã��
	for (int i = 1; i <= v; i++) 
	{
		if (indegree[i] == 0) 
		q.push(i);
	}

	bool isCycle = false;
	while (!q.empty()) {
		if (q.top() >= size) break;
		//ť���� pop�ϰ� �湮ó��
		int now = q.top();
		visit[now] = true;
		printQ.push(now);
		q.pop();
		//pop�� ������ ����� ��������(��������)
		for (int i = 0; i < (int)graph[now].size(); i++) {
			if (visit[graph[now][i]] == true) 
			{ 
				isCycle = true; 
				break; 
			}
			indegree[graph[now][i]]--;	//��������
			if (indegree[graph[now][i]] == 0) 
			{ 
				q.push(graph[now][i]); 
			}	//������ 0�̸� ť�� ����
		}
		if (isCycle) 
			break;
	}

	//����Ŭ�� ����
	if (isCycle) 
		printf("-1");
	else if (printQ.size() != v) 
		printf("-1");
	//����Ŭ�� �������� ����
	else {
		for (int i = 0; !printQ.empty(); i++) 
		{
			printf("%d\n", printQ.front());
			printQ.pop();
		}
	}

	return 0;
}