#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool isMatch(int a, int b) {
    int weightA[7] = {1, 1, 2, 3, 2, 3, 4};
    int weightB[7] = {1, 2, 3, 4, 1, 2, 3};
    for (int i = 0; i < 7; i++)
        if (a * weightA[i] == b * weightB[i])
            return true;
    return false;
}

long long solution(vector<int> weights) {
    sort(weights.begin(), weights.end());
    long long answer = 0;
    for (int i = 0; i < weights.size() - 1; i++)
        for (int j = i + 1; j < weights.size(); j++)
            if (isMatch(weights[i], weights[j]))
                answer++;
    return answer;
}