#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    int answer = -1;
    unordered_set<int> us[8];
    int base = 0;

    for (int i = 0; i < 8; ++i)
    {
        base = 10 * base + N;

        us[i].insert(base);
    }

    if (us[0].count(number) > 0)
    {
        answer = 1;

        return answer;
    }

    for (int i = 1; i < 8; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (const auto& op1 : us[j])
            {
                for (const auto& op2 : us[i - j - 1])
                {
                    us[i].insert(op1 + op2);
                    us[i].insert(op1 - op2);
                    us[i].insert(op1 * op2);

                    if (op2 != 0)
                    {
                        us[i].insert(op1 / op2);
                    }
                }
            }
        }

        if (us[i].count(number) > 0)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}
