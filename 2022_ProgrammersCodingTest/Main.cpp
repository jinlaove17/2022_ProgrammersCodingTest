#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;

    for (int i = 1; i <= number; ++i)
    {
        unordered_set<int> s;
        int si = sqrt(i);

        // ■ 효율적으로 약수 구하기
        // - i의 제곱근까지만 반복하며 나누어 떨어지는 수를 구한다.
        // - i를 나누어 떨어지는 수로, i를 나눈 값 또한 약수가 된다.
        for (int j = 1; j <= si; ++j)
        {
            if (i % j == 0)
            {
                s.emplace(j);
                s.emplace(i / j);
            }
        }

        size_t cnt = s.size();

        if (cnt > limit)
        {
            cnt = power;
        }

        answer += cnt;
    }

    return answer;
}
