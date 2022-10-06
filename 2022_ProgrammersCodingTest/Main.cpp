#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    queue<int> q;

    for (int i = 0; i < bridge_length; ++i)
    {
        q.push(0);
    }

    int size = truck_weights.size();
    int totalWeight = 0;

    for (int i = 0; i < size; )
    {
        totalWeight -= q.front();
        q.pop();

        if (totalWeight + truck_weights[i] <= weight)
        {
            totalWeight += truck_weights[i];
            q.push(truck_weights[i]);
            ++i;
        }
        else
        {
            q.push(0);
        }

        ++answer;
    }

    while (!q.empty())
    {
        q.pop();
        ++answer;
    }

    return answer;
}
