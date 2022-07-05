#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer{};
    int lastNum{ -1 };

    answer.reserve(arr.size());

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
    {
        if (lastNum != *iter)
        {
            lastNum = *iter;
            answer.push_back(lastNum);
        }
    }

    return answer;
}
