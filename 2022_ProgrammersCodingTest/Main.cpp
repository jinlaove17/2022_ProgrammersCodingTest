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

        // �� ȿ�������� ��� ���ϱ�
        // - i�� �����ٱ����� �ݺ��ϸ� ������ �������� ���� ���Ѵ�.
        // - i�� ������ �������� ����, i�� ���� �� ���� ����� �ȴ�.
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
