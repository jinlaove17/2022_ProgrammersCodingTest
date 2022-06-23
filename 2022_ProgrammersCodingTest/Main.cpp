#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int arrSize{ static_cast<int>(arr1.size()) };
    vector<vector<int>> answer{ static_cast<size_t>(arrSize), vector<int>{} };

    for (int i = 0; i < arrSize; ++i)
    {
        int elementCount{ static_cast<int>(arr1[i].size()) };

        for (int j = 0; j < elementCount; ++j)
        {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }

    return answer;
}
