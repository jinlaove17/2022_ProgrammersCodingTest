#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;

    double sizes[200] = {};
    int n = k;

    // 우박수에 따른 구간별 넓이를 계산한다.
    for (int i = 0; i < 200; ++i)
    {
        int next = 0;

        // n이 짝수일 때,
        if ((n & 1) == 0)
        {
            next = n / 2.0;
        }
        // n이 홀수일 때,
        else
        {
            next = 3 * n + 1;
        }

        sizes[i] = (n + next) / 2.0;
        n = next;

        if (n == 1)
        {
            n = i;
            break;
        }
    }

    // 구간별 넓이의 누적합을 계산한다.
    double accSizes[200] = {};

    accSizes[n] = sizes[n];

    for (int i = n - 1; i >= 0; --i)
    {
        accSizes[i] = accSizes[i + 1] + sizes[i];
    }

    // ranges의 구간별 넓이를 계산한다.
    for (const auto& range : ranges)
    {
        int begin = range[0];
        int end = (n + 1) + range[1];

        if (begin <= end)
        {
            answer.push_back(accSizes[begin] - accSizes[end]);
        }
        else
        {
            answer.push_back(-1.0);
        }
    }

    return answer;
}
