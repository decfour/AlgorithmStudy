#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> result;
    vector<int> elements;
    long long total = 1;
    for (int i = 1; i <= n; i++) {
        total *= i;
        elements.push_back(i);
    }
    k--;
    while (n > 0) {
        total /= n;
        int indx = k/total;
        result.push_back(elements[indx]);
        elements.erase(elements.begin() + indx);
        k %= total;
        n--;
    }
    return result;
}