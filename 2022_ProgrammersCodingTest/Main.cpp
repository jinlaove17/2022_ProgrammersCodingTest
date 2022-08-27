#include <string>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int len = name.length();

    // 원점(0)에서 오른쪽으로만 이동하는 데 걸리는 수
    int dist = len - 1;

    for (int i = 0; i < len; ++i)
    {
        answer += min(name[i] - 'A', 26 - (name[i] - 'A'));

        // 오른쪽으로 이동하며, 'A'가 아닌 위치를 찾는다.
        int j = i + 1;

        while (j < len && name[j] == 'A')
        {
            ++j;
        }

        // 가장 적게 걸리는 이동 수를 계산한다.
        // i + i + len - j : i만큼 오른쪽으로 이동 후, 다시 원점(0)으로 돌아오고, j까지 왼쪽으로 이동하는 데 걸리는 수
        // len - j + len - j + i : j까지 왼쪽으로 이동 후, 다시 원점(0)으로 돌아오고, i까지 오른쪽으로 이동하는 데 걸리는 수
        // 두 식을 정리하면 i + len - j + min(i, len - j)로 나타낼 수 있다.
        dist = min(dist, i + len - j + min(i, len - j));
    }

    answer += dist;

    return answer;
}

// 참고 : https://googleyness.tistory.com/16

// 초반에 Greedy 알고리즘으로 풀었었는데, 이 알고리즘으로 해결할 수 없는 테스트 케이스가 존재하여 다른 방법으로 풀게되었다.
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

        // 왼쪽으로 이동하며 바꿔야 할 위치까지의 거리를 구한다.
        int toLeft = 0;

        for (int i = (cursor - 1 + name.length()) % name.length(); i != cursor; i = (i - 1 + name.length()) % name.length())
        {
            ++toLeft;

            if (initName[i] != name[i])
            {
                break;
            }
        }

        // 오른쪽으로 이동하며 바꿔야 할 위치까지의 거리를 구한다.
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
