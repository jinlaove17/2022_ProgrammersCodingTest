#include <cmath>
#include <climits>
#include <queue>

using namespace std;

// 방문한 곳을 또 방문하지 않도록 배열에 기록한다.
bool isVisited[1'000'000];

void DFS(int x, int y, int n, int depth, int& answer);
void BFS(int x, int y, int n, int& answer);

int solution(int x, int y, int n)
{
    int answer = -1;

    BFS(x, y, n, answer);

    return answer;
}

// DFS는 BFS와 달리 최단거리를 보장하지 않기 때문에 답을 찾았더라도 더 작은 값이 나올 수 있다.
// 따라서 시간을 단축하려면 BFS를 사용해야 한다.
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

        // y를 나눈 결과 값이 정수일 경우에만 수행하여 불필요한 연산을 제외시킨다.
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

        // y를 나눈 결과 값이 정수일 경우에만 수행하여 불필요한 연산을 제외시킨다.
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
