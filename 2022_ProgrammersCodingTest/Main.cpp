#include <cmath>

int solution(int n)
{
    int answer{};

    for (int i = 2; i <= n; ++i)
    {
        int sqrtNum = static_cast<int>(sqrt(i));
        bool isDivided{};

        for (int j = 2; j <= sqrtNum; ++j)
        {
            if (i % j == 0)
            {
                isDivided = true;
                break;
            }
        }

        if (!isDivided)
        {
            answer += 1;
        }
    }

    return answer;
}

// 에라토스테네스의 체 알고리즘도 한번 살펴보자.
