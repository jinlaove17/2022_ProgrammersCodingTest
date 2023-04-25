#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    int dirX[] = { 0, 0, -1, 1 };
    int dirY[] = { 1, -1, 0, 0 };

    for (int y = 0; y < maps.size(); ++y)
    {
        for (int x = 0; x < maps[y].length(); ++x)
        {
            if (('0' <= maps[y][x]) && (maps[y][x] <= '9'))
            {
                int total = 0;
                queue<pair<int, int>> q;

                q.push({ x, y });
                total = maps[y][x] - '0';
                maps[y][x] = 'X';

                while (!q.empty())
                {
                    pair<int, int> current = q.front();
                    int cx = current.first;
                    int cy = current.second;

                    q.pop();

                    for (int i = 0; i < 4; ++i)
                    {
                        int nx = cx + dirX[i];
                        int ny = cy + dirY[i];

                        if ((0 <= ny) && (ny < maps.size()) &&
                            (0 <= nx) && (nx < maps[ny].length()) &&
                            ('0' <= maps[ny][nx]) && (maps[ny][nx] <= '9'))
                        {
                            q.push({ nx, ny });
                            total += maps[ny][nx] - '0';
                            maps[ny][nx] = 'X';
                        }
                    }
                }

                answer.push_back(total);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }

    return answer;
}
