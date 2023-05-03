#include <cmath>

using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;

    for (int x = 0; x <= d; x += k)
    {
        long long y = sqrt(static_cast<long long>(d) * d - static_cast<long long>(x) * x);

        answer += y / k + 1;
    }

    return answer;
}
