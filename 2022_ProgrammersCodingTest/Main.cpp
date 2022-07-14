#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int lostCount{ static_cast<int>(lost.size()) };
    int answer{ n - lostCount };

    for (int i = 0; i < lostCount; ++i)
    {
        auto iter{ find_if(reserve.begin(), reserve.end(), [lost, i, &answer](int num) {
            if (num == lost[i])
            {
                answer += 1;

                return true;
            }

            return false;
            }) };

        if (iter != reserve.end())
        {
            lost.erase(find(lost.begin(), lost.end(), lost[i]));
            reserve.erase(iter);

            --i;
        }
    }

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    lostCount = static_cast<int>(lost.size());

    for (int i = 0; i < lostCount; ++i)
    {
        auto iter{ find_if(reserve.begin(), reserve.end(), [lost, i, &answer](int num) {
            if (num == lost[i] - 1)
            {
                answer += 1;

                return true;
            }
            else if (num == lost[i] + 1)
            {
                answer += 1;

                return true;
            }

            return false;
            }) };

        if (iter != reserve.end())
        {
            reserve.erase(iter);
        }
    }

    return answer;
}
