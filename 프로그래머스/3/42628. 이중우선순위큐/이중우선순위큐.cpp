#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for (string op : operations)
        if (op[0] == 'I')
            ms.insert(stoi(op.substr(2)));
        else if (!ms.empty())
            if (op.substr(2) == "1")
                ms.erase(prev(ms.end()));
            else
                ms.erase(ms.begin());
    if (ms.empty()) 
        return {0, 0};
    return {*ms.rbegin(), *ms.begin()};
}