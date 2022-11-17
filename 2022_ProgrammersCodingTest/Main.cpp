#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;

    long queue1Total = 0;
    long queue2Total = 0;

    for (int i = 0; i < queue1.size(); ++i)
    {
        queue1Total += queue1[i];
        queue2Total += queue2[i];
    }

    long goalTotal = queue1Total + queue2Total;

    // 모든 원소의 합이 홀수인 경우 두 큐의 합을 같게 할 수 없으므로 -1을 반환한다.
    if (goalTotal % 2 == 1)
    {
        answer = -1;
    }
    else
    {
        int queue1Index = 0;
        int queue2Index = 0;

        while (true)
        {
            if (queue1Total == queue2Total)
            {
                break;
            }
            else if (queue1Total > queue2Total)
            {
                if (queue1Index < queue1.size())
                {
                    queue1Total -= queue1[queue1Index];
                    queue2Total += queue1[queue1Index];
                }
                else if (queue1Index < queue1.size() + queue2.size())
                {
                    queue1Total -= queue2[queue1Index - queue2.size()];
                    queue2Total += queue2[queue1Index - queue2.size()];
                }
                else
                {
                    answer = -1;

                    break;
                }

                ++queue1Index;
            }
            else
            {
                if (queue2Index < queue2.size())
                {
                    queue2Total -= queue2[queue2Index];
                    queue1Total += queue2[queue2Index];
                }
                else if (queue2Index < queue2.size() + queue1.size())
                {
                    queue2Total -= queue1[queue2Index - queue1.size()];
                    queue1Total += queue1[queue2Index - queue1.size()];
                }
                else
                {
                    answer = -1;

                    break;
                }

                ++queue2Index;
            }

            ++answer;
        }
    }

    return answer;
}
