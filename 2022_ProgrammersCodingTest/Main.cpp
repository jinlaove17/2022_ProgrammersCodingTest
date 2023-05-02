#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    vector<int> wall(n + 1, 1);

    // ĥ�ؾ� �� ���� �κ��� 0���� �ʱ�ȭ�Ѵ�.
    for (int i = 0; i < section.size(); ++i)
    {
        wall[section[i]] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        // ĥ�ؾ� �� ���� �κ��̶��,
        if (wall[i] == 0)
        {
            // �ѷ��� ���̸�ŭ ���� ���������� ĥ�Ѵ�.
            i = i + m - 1;

            // ����Ʈ ĥ Ƚ���� 1 ������Ų��.
            ++answer;
        }
    }

    return answer;
}
