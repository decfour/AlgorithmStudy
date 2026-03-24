using namespace std;

int solution(int n) {
    int targetCount = __builtin_popcount(n);
    int answer = n + 1;
    while (__builtin_popcount(answer) != targetCount)
        answer++;
    return answer;
}