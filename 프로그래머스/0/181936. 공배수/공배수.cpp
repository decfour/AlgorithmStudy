using namespace std;

int solution(int number, int n, int m) {
    return (number % n == 0 && number % m == 0 && number) ? 1 : 0;
}