#include <vector>

using namespace std;

void DFS(int& answer, int k, vector<vector<int>>& dungeons, vector<bool>& isVisited, int depth);

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;

    vector<bool> isVisited(dungeons.size());

    DFS(answer, k, dungeons, isVisited, 0);

    return answer;
}

void DFS(int& answer, int k, vector<vector<int>>& dungeons, vector<bool>& isVisited, int depth)
{
    int size = dungeons.size();

    for (int i = 0; i < size; ++i)
    {
        if (!isVisited[i] && k - dungeons[i][0] >= 0)
        {
            isVisited[i] = true;

            DFS(answer, k - dungeons[i][1], dungeons, isVisited, depth + 1);

            isVisited[i] = false;
        }
    }

    answer = max(answer, depth);
}
