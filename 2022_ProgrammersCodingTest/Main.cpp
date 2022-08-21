#include <string>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    priority_queue<int> maxHeap;

    for (const auto& operation : operations)
    {
        int i = stoi(operation.substr(1, operation.length() - 1));

        switch (operation[0])
        {
        case 'I':
            maxHeap.push(i);
            break;
        case 'D':
            if (!maxHeap.empty())
            {
                switch (i)
                {
                case 1:
                    maxHeap.pop();
                    break;
                case -1:
                {
                    priority_queue<int, vector<int>, greater<int>> minHeap;

                    while (!maxHeap.empty())
                    {
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                    }

                    minHeap.pop();

                    while (!minHeap.empty())
                    {
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                    }
                }
                break;
                }
            }
            break;
        }
    }

    if (maxHeap.empty())
    {
        answer = { 0, 0 };
    }
    else
    {
        answer.push_back(maxHeap.top());

        while (maxHeap.size() > 1)
        {
            maxHeap.pop();
        }

        answer.push_back(maxHeap.top());
    }

    return answer;
}
