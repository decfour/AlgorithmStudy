#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isInside(int x, int y, vector<string> maps) {
    return x >= 0 && x < maps[0].size() && y >= 0 && y < maps.size();
}

vector<int> solution(vector<string> maps) {
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    vector<int> answer;

    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[0].size(); j++)
            if (maps[i][j] != 'X' && !visited[i][j]) {
                int count = 0;
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int mX[4] = {0, 0, -1, 1};
                int mY[4] = {1, -1, 0, 0};
                
                while(!q.empty()) {
                    int currX = q.front().second;
                    int currY = q.front().first;
                    count += (maps[currY][currX] - '0');
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nextX = currX + mX[i];
                        int nextY = currY + mY[i];
                        if (isInside(nextX, nextY, maps) &&
                           maps[nextY][nextX] != 'X' &&
                           !visited[nextY][nextX]) {
                            q.push({nextY, nextX});
                            visited[nextY][nextX] = true;
                        }
                    }
                }
                answer.push_back(count);
            }
    
    if (answer.empty()) {
        answer.push_back(-1);
        return answer;
    }
    else {
        sort(answer.begin(), answer.end());
        return answer;
    }
}