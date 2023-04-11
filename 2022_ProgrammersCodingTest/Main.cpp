#include <vector>

using namespace std;

void DFS(const vector<int>& number, int idx, int total, int depth, int& answer);

int solution(vector<int> number)
{
    int answer = 0;

    for (int i = 0; i < number.size() - 2; ++i)
    {
        DFS(number, i, number[i], 1, answer);
    }

    return answer;
}

void DFS(const vector<int>& number, int idx, int total, int depth, int& answer)
{
    if ((depth == 3) && (total == 0))
    {
        ++answer;
        return;
    }

    for (int i = idx + 1; i < number.size(); ++i)
    {
        DFS(number, i, total + number[i], depth + 1, answer);
    }
}
