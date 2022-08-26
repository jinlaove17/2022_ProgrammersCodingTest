#include <vector>
#include <queue>

using namespace std;

struct POSITION
{
    int x;
    int y;
    int dist;
};

int solution(vector<vector<int>> maps)
{
    int answer = -1;

    const int n = maps.size();
    const int m = maps[0].size();

    queue<POSITION> q;
    POSITION current = { 0, 0, 1 };

    maps[current.x][current.y] = 0;
    q.push(current);

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        if (current.x == n - 1 && current.y == m - 1)
        {
            answer = current.dist;
            break;
        }

        if (current.x - 1 >= 0 && maps[current.x - 1][current.y] == 1)
        {
            maps[current.x - 1][current.y] = 0;
            q.push(POSITION{ current.x - 1, current.y, current.dist + 1 });
        }

        if (current.x + 1 < n && maps[current.x + 1][current.y] == 1)
        {
            maps[current.x + 1][current.y] = 0;
            q.push(POSITION{ current.x + 1, current.y, current.dist + 1 });
        }

        if (current.y - 1 >= 0 && maps[current.x][current.y - 1] == 1)
        {
            maps[current.x][current.y - 1] = 0;
            q.push(POSITION{ current.x, current.y - 1, current.dist + 1 });
        }

        if (current.y + 1 < m && maps[current.x][current.y + 1] == 1)
        {
            maps[current.x][current.y + 1] = 0;
            q.push(POSITION{ current.x, current.y + 1, current.dist + 1 });
        }
    }

    return answer;
}
