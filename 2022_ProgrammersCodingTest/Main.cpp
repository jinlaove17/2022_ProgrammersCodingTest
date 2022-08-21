#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (true)
    {
        int first = pq.top();

        pq.pop();

        if (first >= K)
        {
            break;
        }
        else if (pq.empty())
        {
            answer = -1;
            break;
        }

        int second = pq.top();

        pq.pop();
        pq.push(first + 2 * second);

        ++answer;
    }

    return answer;
}
