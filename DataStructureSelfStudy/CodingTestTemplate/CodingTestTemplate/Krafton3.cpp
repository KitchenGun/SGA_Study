#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include <queue>
#include <string>
#include <vector>

using namespace std;

bool is_valid(vector<string>& plan, vector<vector<bool>>& visited, int x, int y) 
{
    return plan[x][y] != '#' && !visited[x][y];
}

void bfs(vector<string>& plan, vector<vector<bool>>& visited, int x, int y) {
    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };

    queue<pair<int, int>> q;
    q.emplace(x, y);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) 
        {
            int nx = v.first + dx[i], ny = v.second + dy[i];
            if ((0 <= nx && nx < (int)plan.size()) && ((0 <= ny && ny < (int)plan[0].length()))) {
                if (is_valid(plan, visited, nx, ny)) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int solution(vector<string>& plan) {
    int n = plan.size(), m = plan[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));

    int robots = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (plan[i][j] == '*' && !visited[i][j]) {
                bfs(plan, visited, i, j);
                robots++;
            }
        }
    }
    return robots;
}

int main()
{

}