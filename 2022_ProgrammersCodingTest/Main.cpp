#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); ++i)
    {
        q.push(progresses[i]);
    }

    int n = 0;

    while (true)
    {
        int restDay = ceilf((float)(100 - q.front()) / speeds[n]);
        int outCount = 0;

        for (int i = n; i < progresses.size(); ++i)
        {
            int newProgress = q.front() + restDay * speeds[i];

            if (newProgress >= 100)
            {
                q.pop();
                outCount += 1;
            }
            else
            {
                n = i;
                break;
            }
        }

        answer.push_back(outCount);

        if (q.empty())
        {
            break;
        }

        for (int i = n; i < progresses.size(); ++i)
        {
            int newProgress = q.front() + restDay * speeds[i];

            q.pop();
            q.push(newProgress);
        }
    }

    return answer;
}
