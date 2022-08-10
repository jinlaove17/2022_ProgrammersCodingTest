#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    queue<int> indexQueue;
    map<int, int> priorityCounter;

    for (int i = 0; i < priorities.size(); ++i)
    {
        indexQueue.push(i);
        priorityCounter[priorities[i]] += 1;
    }

    int maxPriority = priorityCounter.rbegin()->first;

    while (!indexQueue.empty())
    {
        int currentIndex = indexQueue.front();

        indexQueue.pop();

        if (priorities[currentIndex] == maxPriority)
        {
            answer += 1;

            if (currentIndex == location)
            {
                break;
            }

            priorityCounter[priorities[currentIndex]] -= 1;

            if (priorityCounter[priorities[currentIndex]] == 0)
            {
                priorityCounter.erase(priorities[currentIndex]);
                maxPriority = priorityCounter.rbegin()->first;
            }
        }
        else
        {
            indexQueue.push(currentIndex);
        }
    }

    return answer;
}
