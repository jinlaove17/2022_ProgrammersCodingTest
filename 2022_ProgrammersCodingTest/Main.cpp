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

    // ���� ��ȸ�ϸ�, ���� ����, ����, ���� ������ ��ǥ�� �����Ѵ�.
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

    // ���� �������� ���������� �ð��� ����Ѵ�.
    int time = BFS(maps, isVisited, begin, lever);

    if (time == -1)
    {
        return time;
    }

    // Ż���� �� �־��ٸ�, answer�� �ð��� ����� ���´�.
    answer = time;

    // �湮 ���θ� �ʱ�ȭ �Ѵ�.
    for (int y = 0; y < maps.size(); ++y)
    {
        isVisited[y].assign(maps[y].size(), false);
    }

    // ����� �ð��� �������� ���� ���������� �ð��� ���Ѵ�.
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

            // ���� �ƴ϶�� �ش� ���ڸ� ť�� �߰��Ѵ�.
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
