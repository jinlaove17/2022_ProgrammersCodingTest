#include <string>
#include <array>

using namespace std;

array<array<bool, 2500>, 2500> DP;

int solution(string s)
{
    // ���ĺ� �ϳ��� �Ӹ�����̹Ƿ�, �ּ� ���̴� 1�̴�.
    int answer = 1;

    // ���̰� 1 �Ǵ� 2�� ���ڿ��� �Ӹ�����̹Ƿ�, DP�� ���� �����Ѵ�.
    for (int i = 0; i < s.length(); ++i)
    {
        DP[i][i] = true;

        if (i < s.length() - 1)
        {
            if (s[i] == s[i + 1])
            {
                DP[i][i + 1] = true;
                answer = 2;
            }
        }
    }

    // ���̰� 3�̻��� ���ڿ��� �Ӹ�������� �˻��ϰ�, DP�� ���� �����Ѵ�.
    // ��, �� ��(start, end)�� ���� ���ƾ� �ϰ�, �� ����(start + 1, end - 1)�� �Ӹ�����̸� �����Ѵ�.
    for (int len = 3; len <= s.length(); ++len)
    {
        for (int start = 0; start <= s.length() - len; ++start)
        {
            int end = start + len - 1;

            if (s[start] == s[end] && DP[start + 1][end - 1])
            {
                DP[start][end] = true;
                answer = len;
            }
        }
    }

    return answer;
}

// ����: https://yabmoons.tistory.com/545?category=946153
