#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    const int row = arr1.size();
    const int column = arr2[0].size();

    answer.resize(row);

    for (int i = 0; i < row; ++i)
    {
        answer[i].resize(column);

        for (int j = 0; j < column; ++j)
        {
            for (int k = 0; k < arr1[i].size(); ++k)
            {
                answer[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }

    return answer;
}
