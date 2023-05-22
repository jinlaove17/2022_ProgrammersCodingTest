#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;

    long long rr1 = static_cast<long long>(r1) * r1;
    long long rr2 = static_cast<long long>(r2) * r2;

    // ��п� ���� �ִ� ���� ������ ���� �Ŀ� 4�� ���� ���̴�.
    for (int x = 0; x <= r2; ++x)
    {
        long long xx = static_cast<long long>(x) * x;

        // ���� �������� �̿��Ͽ�, x�� ���� ū ���� y���� ����Ѵ�.
        long long y2 = sqrt(rr2 - xx);
        long long y = 0;

        if (x < r1)
        {
            // ���� �������� �̿��Ͽ�, x�� ���� ���� ���� y���� ����Ѵ�.
            double y1 = sqrt(rr1 - xx);

            // ���� y1�� ������ �ƴ϶��, 1�� ���� ������ ����ؾ� �Ѵ�.
            y = y1;

            if (y1 > y)
            {
                ++y;
            }
        }

        answer += (y2 - y + 1);
    }

    // �ߺ��� �κ��� ������ �ʵ��� ��п��� ���� �������� x = 0�� ���� ���� ������ ���� ���� ����� ���� ������ ���Ѵ�.
    answer -= (r2 - r1 + 1);

    // ��� ���� 4���Ͽ� ���� ���� ������ ���Ѵ�.
    return 4 * answer;
}
