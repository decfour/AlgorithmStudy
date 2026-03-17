#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> q;
    for (int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        q.push(enemy[i]);
        if (n < 0)
            if (k > 0) {
                n += q.top();
                q.pop();
                k--;
            }
            else
                return i;
    }
    return enemy.size();
}