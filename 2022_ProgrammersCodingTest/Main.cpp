#include <cmath>

long long solution(long long n)
{
    long long answer{};
    double sqrtN = sqrt(n);

    if (sqrtN == (int)sqrtN)
    {
        answer = pow(sqrtN + 1, 2);
    }
    else
    {
        answer = -1;
    }

    return answer;
}
