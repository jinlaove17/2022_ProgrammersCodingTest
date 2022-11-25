#include <vector>
#include <algorithm>

using namespace std;

int Kruskal(int n, vector<vector<int>>& costs);
int GetRoot(const vector<int>& parents, int current);
void SetUnion(vector<int>& parents, int root1, int root2);

int solution(int n, vector<vector<int>> costs)
{
    int answer = Kruskal(n, costs);

    return answer;
}

int Kruskal(int n, vector<vector<int>>& costs)
{
    sort(costs.begin(), costs.end(), [](const vector<int>& v1, const vector<int>& v2)
        {
            return v1[2] < v2[2];
        });

    vector<int> parents(n);

    // 자기 자신의 인덱스를 부모로 만든다.
    for (int i = 0; i < n; ++i)
    {
        parents[i] = i;
    }

    int totalCost = 0;

    // n - 1개의 간선을 선택할 때까지 반복한다.
    for (int i = 0, j = 0; i < n - 1; ++j)
    {
        int root1 = GetRoot(parents, costs[j][0]);
        int root2 = GetRoot(parents, costs[j][1]);

        // 두 정점이 다른 집합이라면 합친다.
        if (root1 != root2)
        {
            SetUnion(parents, root1, root2);
            totalCost += costs[j][2];
            ++i;
        }
    }

    return totalCost;
}

int GetRoot(const vector<int>& parents, int current)
{
    while (parents[current] != current)
    {
        current = parents[current];
    }

    return current;
}

void SetUnion(vector<int>& parents, int root1, int root2)
{
    if (root1 < root2)
    {
        parents[root2] = root1;
    }
    else
    {
        parents[root1] = root2;
    }
}
