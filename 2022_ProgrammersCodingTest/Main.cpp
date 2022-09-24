#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    answer.reserve(right - left + 1);

    // left�� right�� ���� �׷��� ��ȣ�� ���Ѵ�.
    int leftGroup = left / n + 1;
    int rightGroup = right / n + 1;

    // left �׷���� right �׷���� ��ȸ�ϸ�, answer�� ���� ä���.
    for (int i = leftGroup; i <= rightGroup; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            answer.push_back(i);
        }

        for (int k = 0, num = i + 1; k < n - i; ++k, ++num)
        {
            answer.push_back(num);
        }
    }

    // �� �׷쿡�� left, right��ŭ �̵��Ͽ� ���۰� �� ��ġ�� ���ϰ�, answer�� ���Ҵ��Ѵ�.
    answer.assign(answer.begin() + left % n, answer.end() - (n - right % n) + 1);

    return answer;
}
