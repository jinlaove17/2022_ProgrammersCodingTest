#include <vector>
#include <climits>

using namespace std;

int totals[1'000'000];

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer(2);

    if (sequence[0] == k)
    {
        return answer;
    }

    // sequence 벡터를 순회하며 연속된 부분수열의 누적합을 계산한다.
    totals[0] = sequence[0];

    for (int i = 1; i < sequence.size(); ++i)
    {
        if (sequence[i] == k)
        {
            answer[0] = answer[1] = i;

            return answer;
        }

        totals[i] = totals[i - 1] + sequence[i];
    }

    // 투 포인터를 활용하여 begin의 위치에서부터 값을 비교해나간다.
    int begin = 0, end = 1;
    int minLen = INT_MAX;

    while ((begin < end) && (end < sequence.size()))
    {
        int total = totals[end] - totals[begin] + sequence[begin];

        if (total == k)
        {
            int len = end - begin + 1;

            if (len < minLen)
            {
                minLen = len;
                answer[0] = begin;
                answer[1] = end;
            }

            ++begin;
        }
        else if (total < k)
        {
            ++end;
        }
        else
        {
            ++begin;
        }
    }

    return answer;
}
