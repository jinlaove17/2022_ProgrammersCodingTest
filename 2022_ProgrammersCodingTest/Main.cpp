#include <string>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int len = name.length();

    // ����(0)���� ���������θ� �̵��ϴ� �� �ɸ��� ��
    int dist = len - 1;

    for (int i = 0; i < len; ++i)
    {
        answer += min(name[i] - 'A', 26 - (name[i] - 'A'));

        // ���������� �̵��ϸ�, 'A'�� �ƴ� ��ġ�� ã�´�.
        int j = i + 1;

        while (j < len && name[j] == 'A')
        {
            ++j;
        }

        // ���� ���� �ɸ��� �̵� ���� ����Ѵ�.
        // i + i + len - j : i��ŭ ���������� �̵� ��, �ٽ� ����(0)���� ���ƿ���, j���� �������� �̵��ϴ� �� �ɸ��� ��
        // len - j + len - j + i : j���� �������� �̵� ��, �ٽ� ����(0)���� ���ƿ���, i���� ���������� �̵��ϴ� �� �ɸ��� ��
        // �� ���� �����ϸ� i + len - j + min(i, len - j)�� ��Ÿ�� �� �ִ�.
        dist = min(dist, i + len - j + min(i, len - j));
    }

    answer += dist;

    return answer;
}

// ���� : https://googleyness.tistory.com/16

// �ʹݿ� Greedy �˰������� Ǯ�����µ�, �� �˰������� �ذ��� �� ���� �׽�Ʈ ���̽��� �����Ͽ� �ٸ� ������� Ǯ�ԵǾ���.
/*
int solution(string name)
{
    int answer = 0;
    string initName;

    for (int i = 0; i < name.length(); ++i)
    {
        initName.push_back('A');
    }

    int cursor = 0;

    while (true)
    {
        int toNext = name[cursor] - initName[cursor];
        int toPrev = 26 - toNext;

        answer += min(toNext, toPrev);
        initName[cursor] = name[cursor];

        if (initName == name)
        {
            break;
        }

        // �������� �̵��ϸ� �ٲ�� �� ��ġ������ �Ÿ��� ���Ѵ�.
        int toLeft = 0;

        for (int i = (cursor - 1 + name.length()) % name.length(); i != cursor; i = (i - 1 + name.length()) % name.length())
        {
            ++toLeft;

            if (initName[i] != name[i])
            {
                break;
            }
        }

        // ���������� �̵��ϸ� �ٲ�� �� ��ġ������ �Ÿ��� ���Ѵ�.
        int toRight = 0;

        for (int i = (cursor + 1) % name.length(); i != cursor; i = (i + 1) % name.length())
        {
            ++toRight;

            if (initName[i] != name[i])
            {
                break;
            }
        }

        if (toLeft < toRight)
        {
            cursor = (cursor - toLeft + name.length()) % name.length();
            answer += toLeft;
        }
        else
        {
            cursor = (cursor + toRight) % name.length();
            answer += toRight;
        }
    }

    return answer;
}
*/
