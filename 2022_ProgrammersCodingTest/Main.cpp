#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;

    vector<vector<int>> v(n, vector<int>(n));

    int dir = 0;
    int x = 0;
    int y = 0;
    int num = 1;

    for (int i = 0; i < n; ++i)
    {
        switch (dir)
        {
        case 0: // Down
            for (int j = i; j < n; ++j)
            {
                v[y++][x] = num++;
            }
            --y;
            ++x;
            break;
        case 1: // Right
            for (int j = i; j < n; ++j)
            {
                v[y][x++] = num++;
            }
            --y;
            x -= 2;
            break;
        case 2: // Left Up
            for (int j = i; j < n; ++j)
            {
                v[y--][x--] = num++;
            }
            y += 2;
            ++x;
            break;
        }

        dir = (dir + 1) % 3;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            answer.push_back(v[i][j]);
        }
    }

    return answer;
}
