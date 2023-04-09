#include <vector>

using namespace std;

enum class STATE
{
    ZERO,
    ONE,
    MIXED
};

STATE CheckState(const vector<vector<int>>& arr, int size, int row, int col);
void Compress(vector<int>& answer, const vector<vector<int>>& arr, int size, int row, int col);

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer(2);

    Compress(answer, arr, arr.size(), 0, 0);

    return answer;
}

STATE CheckState(const vector<vector<int>>& arr, int size, int row, int col)
{
    int startValue = arr[row][col];

    for (int i = row; i < row + size; ++i)
    {
        for (int j = col; j < col + size; ++j)
        {
            if (arr[i][j] != startValue)
            {
                return STATE::MIXED;
            }
        }
    }

    switch (startValue)
    {
    case 0:
        return STATE::ZERO;
    case 1:
        return STATE::ONE;
    }

    return STATE::MIXED;
}

void Compress(vector<int>& answer, const vector<vector<int>>& arr, int size, int row, int col)
{
    switch (CheckState(arr, size, row, col))
    {
    case STATE::ZERO:
        ++answer[0];
        return;
    case STATE::ONE:
        ++answer[1];
        return;
    }

    int halfSize = size / 2;

    if (halfSize > 0)
    {
        Compress(answer, arr, halfSize, row, col);
        Compress(answer, arr, halfSize, row + halfSize, col);
        Compress(answer, arr, halfSize, row, col + halfSize);
        Compress(answer, arr, halfSize, row + halfSize, col + halfSize);
    }
}
