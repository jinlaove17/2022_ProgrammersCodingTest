#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    // �ʱ� ���� �������� �����̴�.
    int answer = k;
    int round = enemy.size();

    // ����� �� �ִ� �������� ���� ���� ���� ũ�ų� ���ٸ�, ��� ���忡 �������� ����ϸ� �ǹǷ� ���� ���� ��ȯ�Ѵ�.
    if (k >= round)
    {
        return round;
    }

    // �ִ��� ���� ���带 ���� ���ؼ��� �������� ��� ����ؾ� �Ѵ�.
    // �켱, 1������� k������� �������� ����ϰ�, ���� �� ���� ���� ���� �ִ� ���尡 �ִٸ� �������� ��� ���带 ��ü�Ѵ�.
    // �������� ����� ������ ���� ���� �ּ� ���� ������ ���´�.
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < k; ++i)
    {
        q.push(enemy[i]);
    }

    // k + 1������� ��ȸ�� �����Ѵ�.
    for (int i = k; i < round; ++i)
    {
        // ť�� top�� �������� ����� ���� �� ���� ���� ���� ���� ��Ÿ����.
        int minEnemy = q.top();

        // ���� ������ ���� ���� minEnemy�� ���Ѵ�.
        if (enemy[i] > minEnemy)
        {
            // ���� ������ ���� ���� �� ���� ������, ���Ǽ��� minEnemy�� ����� �������� ������� ���� ���尡 �ǹǷ� ������ ������ ���ش�.
            int rest = n - minEnemy;

            // ���� �ش� ���忡 �������� ������� �ʾ��� �� ������ ���� �� ���� ��쿡��, ������ ��� ���带 ��ü�� �� �ִ�.
            if (rest >= 0)
            {
                q.pop();
                q.push(enemy[i]);
                answer = i + 1;
                n = rest;
            }
            else
            {
                break;
            }
        }
        // minEnemy���� �̹� ������ ���� ���� �� ���ٸ�, �������� ������� �ʰ� ������ ���� ���Ƴ���.
        else
        {
            int rest = n - enemy[i];

            if (rest >= 0)
            {
                ++answer;
                n = rest;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}
