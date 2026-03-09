#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int toMin(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int,int>> times;
    for(int i = 0; i < book_time.size(); i++) {
        int start = toMin(book_time[i][0]);
        int end = toMin(book_time[i][1]) + 10;
        times.push_back({start, end});
    }
    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < times.size(); i++) {
        int start = times[i].first;
        int end = times[i].second;
        if(!pq.empty() && pq.top() <= start)
            pq.pop();
        pq.push(end);
    }
    return pq.size();
}