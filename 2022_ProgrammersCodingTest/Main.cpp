#include <vector>

using namespace std;

int DFS(int n, int current, const vector<vector<bool>>& adjMat, vector<bool>& isVisited);

int solution(int n, vector<vector<int>> wires)
{
    int answer = INT_MAX;

    vector<vector<bool>> adjMat(n + 1, vector<bool>(n + 1));

    for (int i = 0; i < wires.size(); ++i)
    {
        int u = wires[i][0];
        int v = wires[i][1];

        adjMat[u][v] = adjMat[v][u] = true;
    }

    for (int i = 0; i < wires.size(); ++i)
    {
        int u = wires[i][0];
        int v = wires[i][1];

        adjMat[u][v] = adjMat[v][u] = false;

        vector<bool> isVisited(n + 1);
        vector<int> groupCount;

        // 하나의 전선을 끊었기 때문에 무조건 2그룹으로 나뉘게 된다.
        groupCount.reserve(2);

        for (int i = 1; i <= n; ++i)
        {
            int count = DFS(n, i, adjMat, isVisited);

            if (count)
            {
                groupCount.push_back(count);
            }
        }

        answer = min(answer, abs(groupCount[0] - groupCount[1]));
        adjMat[u][v] = adjMat[v][u] = true;

        if (answer == 0)
        {
            break;
        }
    }

    return answer;
}

int DFS(int n, int current, const vector<vector<bool>>& adjMat, vector<bool>& isVisited)
{
    int count = 0;

    if (!isVisited[current])
    {
        isVisited[current] = true;
        count = 1;

        for (int i = 1; i <= n; ++i)
        {
            if (!isVisited[i] && adjMat[current][i])
            {
                count += DFS(n, i, adjMat, isVisited);
            }
        }
    }

    return count;
}
