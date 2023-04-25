#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (const auto& place : places)
    {
        int possible = 1;

        for (int y = 0; y < 5; ++y)
        {
            for (int x = 0; x < 5; ++x)
            {
                if (place[y][x] == 'P')
                {
                    // 1. 현재 개발자의 위치에서 상, 하, 좌, 우 맨해튼 거리 내에 다른 개발자가 앉아 있는지 검사한다.
                    if (((y - 1 >= 0) && (place[y - 1][x] == 'P')) ||
                        ((y + 1 < 5) && (place[y + 1][x] == 'P')) ||
                        ((x - 1 >= 0) && (place[y][x - 1] == 'P')) ||
                        ((x + 1 < 5) && (place[y][x + 1] == 'P')))
                    {
                        possible = 0;
                        break;
                    }

                    if (((y - 2 >= 0) && (place[y - 2][x] == 'P') && (place[y - 1][x] != 'X')) ||
                        ((y + 2 < 5) && (place[y + 2][x] == 'P') && (place[y + 1][x] != 'X')) ||
                        ((x - 2 >= 0) && (place[y][x - 2] == 'P') && (place[y][x - 1] != 'X')) ||
                        ((x + 2 < 5) && (place[y][x + 2] == 'P') && (place[y][x + 1] != 'X')))
                    {
                        possible = 0;
                        break;
                    }

                    // 2. 현재 개발자의 위치에서 대각선 맨해튼 거리 내에 다른 개발자가 앉아 있는지 검사한다.
                    if (((y - 1 >= 0) && (x - 1 >= 0) && (place[y - 1][x - 1] == 'P') && ((place[y - 1][x] != 'X') || (place[y][x - 1] != 'X'))) ||
                        ((y - 1 >= 0) && (x + 1 < 5) && (place[y - 1][x + 1] == 'P') && ((place[y - 1][x] != 'X') || (place[y][x + 1] != 'X'))) ||
                        ((y + 1 < 5) && (x - 1 >= 0) && (place[y + 1][x - 1] == 'P') && ((place[y + 1][x] != 'X') || (place[y][x - 1] != 'X'))) ||
                        ((y + 1 < 5) && (x + 1 < 5) && (place[y + 1][x + 1] == 'P') && ((place[y + 1][x] != 'X') || (place[y][x + 1] != 'X'))))
                    {
                        possible = 0;
                        break;
                    }
                }
            }

            if (possible == 0)
            {
                break;
            }
        }

        answer.push_back(possible);
    }

    return answer;
}
