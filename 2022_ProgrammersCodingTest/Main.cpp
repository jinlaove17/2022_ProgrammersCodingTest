#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;

    int time;
};

int dirX[] = {  0, 0, -1, 1 };
int dirY[] = { -1, 1,  0, 0 };

int BFS(const vector<string>& maps, vector<vector<bool>>& isVisited, const pair<int, int>& begin, const pair<int, int>& end);

int solution(vector<string> maps)
{
    int answer = 0;

    vector<vector<bool>> isVisited(maps.size());
    pair<int, int> begin, lever, end;

    // 맵을 순회하며, 시작 지점, 레버, 도착 지점의 좌표를 저장한다.
    for (int y = 0; y < maps.size(); ++y)
    {
        isVisited[y].resize(maps[y].size());

        for (int x = 0; x < maps[y].size(); ++x)
        {
            switch (maps[y][x])
            {
            case 'S':
                begin.first = x;
                begin.second = y;
                break;
            case 'L':
                lever.first = x;
                lever.second = y;
                break;
            case 'E':
                end.first = x;
                end.second = y;
                break;
            }
        }
    }

    // 시작 지점에서 레버까지의 시간을 계산한다.
    int time = BFS(maps, isVisited, begin, lever);

    if (time == -1)
    {
        return time;
    }

    // 탈출할 수 있었다면, answer에 시간을 기록해 놓는다.
    answer = time;

    // 방문 여부를 초기화 한다.
    for (int y = 0; y < maps.size(); ++y)
    {
        isVisited[y].assign(maps[y].size(), false);
    }

    // 기록한 시간에 레버에서 도착 지점까지의 시간을 더한다.
    time = BFS(maps, isVisited, lever, end);

    if (time == -1)
    {
        return time;
    }

    answer += time;

    return answer;
}

int BFS(const vector<string>& maps, vector<vector<bool>>& isVisited, const pair<int, int>& begin, const pair<int, int>& end)
{
    queue<Node> q;

    isVisited[begin.second][begin.first] = true;
    q.push({ begin.first, begin.second, 0 });

    while (!q.empty())
    {
        Node node = q.front();

        q.pop();

        if ((node.x == end.first) && (node.y == end.second))
        {
            return node.time;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = node.x + dirX[i];
            int ny = node.y + dirY[i];

            // 벽이 아니라면 해당 격자를 큐에 추가한다.
            if ((0 <= ny) && (ny < isVisited.size()) &&
                (0 <= nx) && (nx < isVisited[ny].size()) &&
                (!isVisited[ny][nx]) && (maps[ny][nx] != 'X'))
            {
                isVisited[ny][nx] = true;
                q.push({ nx, ny, node.time + 1 });
            }
        }
    }

    return -1;
}
