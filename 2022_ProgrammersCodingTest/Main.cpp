#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    unordered_set<int> visited;

    for (int i = 0; i < n; ++i)
    {
        if (visited.find(i) != visited.end())
        {
            continue;
        }

        visited.insert(i);

        queue<int> q;

        q.push(i);

        while (!q.empty())
        {
            int current = q.front();

            q.pop();

            for (int j = 0; j < n; ++j)
            {
                if (computers[current][j] == 1 && visited.find(j) == visited.end())
                {
                    q.push(j);
                    visited.insert(j);
                }
            }
        }

        ++answer;
    }

    return answer;
}
