#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands)
{
    vector<int> answer{};

    answer.reserve(commands.size());

    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> dividedArr{};

        dividedArr.reserve(commands[i][1] - commands[i][0] + 1);

        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; ++j)
        {
            dividedArr.push_back(arr[j]);
        }

        sort(dividedArr.begin(), dividedArr.end());

        answer.push_back(dividedArr[commands[i][2] - 1]);
    }

    return answer;
}
