#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int v, n;
	cin>>v>>n;

	const int size = v+1;

	vector<vector<int>> graph(size);	//정점과 간선정보를 저장할 벡터
	vector<int> indegree(size,0);	//정점의 indegree(차수)를 저장할 벡터
	int a, b;
	for (int i = 0; i < n; i++) {
		cin>>a>>b;
		graph[a].push_back(b);	//연결
		indegree[b]++;	//차수올림
	}

	priority_queue <int, vector<int>, greater<int> > q;
	queue <int> printQ;	//출력용 큐
	vector<bool> visit(size,false);	//방문체크, 싸이클 존재여부판단

	//처음 차수가 0인정점 찾기
	for (int i = 1; i <= v; i++) 
	{
		if (indegree[i] == 0) 
		q.push(i);
	}

	bool isCycle = false;
	while (!q.empty()) {
		if (q.top() >= size) break;
		//큐에서 pop하고 방문처리
		int now = q.top();
		visit[now] = true;
		printQ.push(now);
		q.pop();
		//pop한 정점과 연결된 간선제거(차수내림)
		for (int i = 0; i < (int)graph[now].size(); i++) {
			if (visit[graph[now][i]] == true) 
			{ 
				isCycle = true; 
				break; 
			}
			indegree[graph[now][i]]--;	//차수내림
			if (indegree[graph[now][i]] == 0) 
			{ 
				q.push(graph[now][i]); 
			}	//차수가 0이면 큐에 넣음
		}
		if (isCycle) 
			break;
	}

	//싸이클이 존재
	if (isCycle) 
		printf("-1");
	else if (printQ.size() != v) 
		printf("-1");
	//싸이클이 존재하지 않음
	else {
		for (int i = 0; !printQ.empty(); i++) 
		{
			printf("%d\n", printQ.front());
			printQ.pop();
		}
	}

	return 0;
}