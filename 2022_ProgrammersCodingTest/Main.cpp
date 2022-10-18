#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<int> answer;

    answer.reserve(n);

    vector<long long> f(n + 1, 1);

    for (int i = 2; i <= n; ++i)
    {
        f[i] = i * f[i - 1];
    }

    set<int> s;

    for (int i = 1; i <= n; ++i)
    {
        s.insert(i);
    }

    for (int i = n; i >= 1; --i)
    {
        long long period = f[i] / i;
        long long group = ceill((double)k / period);
        auto iter = s.begin();

        advance(iter, group - 1);

        int num = *iter;

        s.erase(num);
        answer.push_back(num);

        k %= period;

        if (k == 0)
        {
            for (auto it = s.rbegin(); it != s.rend(); ++it)
            {
                answer.push_back(*it);
            }

            break;
        }
        else if (k == 1)
        {
            for (auto it = s.begin(); it != s.end(); ++it)
            {
                answer.push_back(*it);
            }

            break;
        }
    }

    return answer;
}
