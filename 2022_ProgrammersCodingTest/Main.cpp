#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    const int row = land.size();
    const int col = 4;

    for (int i = 1; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            land[i][j] += max(land[i - 1][(j + 1) % col], max(land[i - 1][(j + 2) % col], land[i - 1][(j + 3) % col]));
        }
    }

    return max(land[row - 1][0], max(land[row - 1][1], max(land[row - 1][2], land[row - 1][3])));
}
