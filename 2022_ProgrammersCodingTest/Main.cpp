#include <vector>

using namespace std;

int FindMinNode(int N, const vector<int>& distance, const vector<bool>& isVisited);

int solution(int N, vector<vector<int>> road, int K)
{
    // 1번 마을은 무조건 배달이 가능하다.
    int answer = 1;

    // 각 마을 간의 최소 시간(가중치)을 계산한다.
    vector<vector<int>> g(N, vector<int>(N, INT_MAX));

    for (int i = 0; i < road.size(); ++i)
    {
        if (g[road[i][0] - 1][road[i][1] - 1] > road[i][2])
        {
            // 양방향이기 때문에 반대도 설정해준다.
            g[road[i][0] - 1][road[i][1] - 1] = road[i][2];
            g[road[i][1] - 1][road[i][0] - 1] = road[i][2];
        }
    }

    // 다익스트라 알고리즘
    vector<int> distance(N);
    vector<bool> isVisited(N);
    int start = 0;

    for (int i = 0; i < N; ++i)
    {
        distance[i] = g[start][i];
    }

    isVisited[start] = true;

    for (int i = 0; i < N - 1; ++i)
    {
        int node = FindMinNode(N, distance, isVisited);

        if (node == -1)
        {
            break;
        }

        isVisited[node] = true;

        for (int j = 0; j < N; ++j)
        {
            // 인접한 노드의 거리를 갱신한다.
            if (!isVisited[j] && g[node][j] != INT_MAX)
            {
                if (distance[j] > distance[node] + g[node][j])
                {
                    distance[j] = distance[node] + g[node][j];
                }
            }
        }
    }

    for (int i = 1; i < N; ++i)
    {
        if (distance[i] <= K)
        {
            ++answer;
        }
    }

    return answer;
}

int FindMinNode(int N, const vector<int>& distance, const vector<bool>& isVisited)
{
    int minNode = -1;
    int minValue = INT_MAX;

    for (int i = 0; i < N; ++i)
    {
        if (!isVisited[i] && distance[i] < minValue)
        {
            minNode = i;
            minValue = distance[i];
        }
    }

    return minNode;
}
