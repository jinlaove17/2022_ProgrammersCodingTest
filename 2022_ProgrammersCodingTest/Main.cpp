#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool CanAllDiscount(vector<string>& want, vector<int>& number, unordered_map<string, int>& um);

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    unordered_map<string, int> um;

    for (int i = 0; i < 10; ++i)
    {
        ++um[discount[i]];
    }

    if (CanAllDiscount(want, number, um))
    {
        ++answer;
    }

    for (int i = 1; i <= discount.size() - 10; ++i)
    {
        --um[discount[i - 1]];
        ++um[discount[i + 9]];

        if (CanAllDiscount(want, number, um))
        {
            ++answer;
        }
    }

    return answer;
}

bool CanAllDiscount(vector<string>& want, vector<int>& number, unordered_map<string, int>& um)
{
    bool canAllDiscount = true;

    for (int i = 0; i < want.size(); ++i)
    {
        if (um[want[i]] < number[i])
        {
            canAllDiscount = false;
            break;
        }
    }

    return canAllDiscount;
}
