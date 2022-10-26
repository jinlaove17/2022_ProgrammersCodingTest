#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    int answer = 0;

    queue<int> q;

    for (int i = 0; i < order.size(); ++i)
    {
        q.push(i + 1);
    }

    stack<int> s;
    int idx = 0;

    while (!q.empty())
    {
        if (!s.empty())
        {
            if (s.top() == order[idx])
            {
                s.pop();
                ++idx;
                ++answer;

                continue;
            }
        }

        int front = q.front();

        q.pop();

        if (front != order[idx])
        {
            s.push(front);
        }
        else
        {
            ++idx;
            ++answer;
        }
    }

    while (!s.empty())
    {
        if (s.top() != order[idx])
        {
            break;
        }

        s.pop();
        ++idx;
        ++answer;
    }

    return answer;
}
