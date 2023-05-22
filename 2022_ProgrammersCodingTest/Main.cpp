#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;

    long long rr1 = static_cast<long long>(r1) * r1;
    long long rr2 = static_cast<long long>(r2) * r2;

    // 사분원 내에 있는 점의 개수를 구한 후에 4배 해줄 것이다.
    for (int x = 0; x <= r2; ++x)
    {
        long long xx = static_cast<long long>(x) * x;

        // 원의 방정식을 이용하여, x일 때의 큰 원의 y값을 계산한다.
        long long y2 = sqrt(rr2 - xx);
        long long y = 0;

        if (x < r1)
        {
            // 원의 방정식을 이용하여, x일 때의 작은 원의 y값을 계산한다.
            double y1 = sqrt(rr1 - xx);

            // 만약 y1이 정수가 아니라면, 1을 더한 값부터 계산해야 한다.
            y = y1;

            if (y1 > y)
            {
                ++y;
            }
        }

        answer += (y2 - y + 1);
    }

    // 중복된 부분이 생기지 않도록 사분원에 점의 개수에서 x = 0일 때의 점의 개수를 빼서 갈고리 모양의 점의 개수를 구한다.
    answer -= (r2 - r1 + 1);

    // 결과 값에 4배하여 원에 점의 개수를 구한다.
    return 4 * answer;
}
