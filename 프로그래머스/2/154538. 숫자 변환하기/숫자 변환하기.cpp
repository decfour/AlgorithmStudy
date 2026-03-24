#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int x, int y, int n) {
    queue<pair<int, int>> q;
    vector<bool> visited(1000001, false);
    q.push({x, 0});
    visited[x] = true;
    
    while(!q.empty()) {
        int curr = q.front().first;
        int count = q.front().second;
        q.pop();
        if (curr == y)
            return count;
        if (!visited[curr + n] && curr + n <= y) {
            q.push({curr + n, count + 1});
            visited[curr + n] = true;
        }
        if (!visited[curr * 2] && curr * 2 <= y) {
            q.push({curr * 2, count + 1});
            visited[curr * 2] = true;
        }
        if (!visited[curr * 3] && curr * 3 <= y) {
            q.push({curr * 3, count + 1});
            visited[curr * 3] = true;
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x, y, n);
}