#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer{};
    int usedBudget{};

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); ++i)
    {
        if (usedBudget + d[i] <= budget)
        {
            usedBudget += d[i];
            answer += 1;
        }
        else
        {
            break;
        }
    }

    return answer;
}
