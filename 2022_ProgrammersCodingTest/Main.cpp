#include <cmath>
#include <climits>
#include <queue>

using namespace std;

// �湮�� ���� �� �湮���� �ʵ��� �迭�� ����Ѵ�.
bool isVisited[1'000'000];

void DFS(int x, int y, int n, int depth, int& answer);
void BFS(int x, int y, int n, int& answer);

int solution(int x, int y, int n)
{
    int answer = -1;

    BFS(x, y, n, answer);

    return answer;
}

// DFS�� BFS�� �޸� �ִܰŸ��� �������� �ʱ� ������ ���� ã�Ҵ��� �� ���� ���� ���� �� �ִ�.
// ���� �ð��� �����Ϸ��� BFS�� ����ؾ� �Ѵ�.
void DFS(int x, int y, int n, int depth, int& answer)
{
    if (x == y)
    {
        answer = min(answer, depth);
    }
    else if (y > x)
    {
        if ((y - n >= 0) && (!isVisited[y - n]))
        {
            isVisited[y - n] = true;
            DFS(x, y - n, n, depth + 1, answer);
            isVisited[y - n] = false;
        }

        // y�� ���� ��� ���� ������ ��쿡�� �����Ͽ� ���ʿ��� ������ ���ܽ�Ų��.
        if ((y % 2 == 0) && (!isVisited[y / 2]))
        {
            isVisited[y / 2] = true;
            DFS(x, y / 2, n, depth + 1, answer);
            isVisited[y / 2] = false;
        }

        if ((y % 3 == 0) && (!isVisited[y / 3]))
        {
            isVisited[y / 3] = true;
            DFS(x, y / 3, n, depth + 1, answer);
            isVisited[y / 3] = false;
        }
    }
}

void BFS(int x, int y, int n, int& answer)
{
    queue<pair<int, int>> q;
    int count = 0;

    isVisited[y] = true;
    q.push(make_pair(count, y));

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        if (current.second == x)
        {
            answer = current.first;
            break;
        }

        if ((current.second - n >= 0) && (!isVisited[current.second - n]))
        {
            isVisited[current.second - n] = true;
            q.push(make_pair(current.first + 1, current.second - n));
        }

        // y�� ���� ��� ���� ������ ��쿡�� �����Ͽ� ���ʿ��� ������ ���ܽ�Ų��.
        if ((current.second % 2 == 0) && (!isVisited[current.second / 2]))
        {
            isVisited[current.second / 2] = true;
            q.push(make_pair(current.first + 1, current.second / 2));
        }

        if ((current.second % 3 == 0) && (!isVisited[current.second / 3]))
        {
            isVisited[current.second / 3] = true;
            q.push(make_pair(current.first + 1, current.second / 3));
        }
    }
}
