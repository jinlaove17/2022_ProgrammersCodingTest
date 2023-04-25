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
                    // 1. ���� �������� ��ġ���� ��, ��, ��, �� ����ư �Ÿ� ���� �ٸ� �����ڰ� �ɾ� �ִ��� �˻��Ѵ�.
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

                    // 2. ���� �������� ��ġ���� �밢�� ����ư �Ÿ� ���� �ٸ� �����ڰ� �ɾ� �ִ��� �˻��Ѵ�.
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
