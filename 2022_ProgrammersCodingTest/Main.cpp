#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    unordered_map<int, int> um[2];

    ++um[0][topping[0]];

    for (int i = 1; i < topping.size(); ++i)
    {
        ++um[1][topping[i]];
    }

    if (um[0].size() == um[1].size())
    {
        ++answer;
    }

    for (int i = 1; i < topping.size(); ++i)
    {
        ++um[0][topping[i]];
        --um[1][topping[i]];

        if (um[1][topping[i]] == 0)
        {
            um[1].erase(topping[i]);
        }

        if (um[0].size() == um[1].size())
        {
            ++answer;
        }
    }

    return answer;
}
