#include <vector>

using namespace std;

void HanoiTop(vector<vector<int>>& answer, int n, int start, int end, int bypass);

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer{};

    HanoiTop(answer, n, 1, 3, 2);

    return answer;
}

void HanoiTop(vector<vector<int>>& answer, int n, int start, int end, int bypass)
{
    if (n == 1)
    {
        answer.push_back({ start, end });
    }
    else
    {
        HanoiTop(answer, n - 1, start, bypass, end);
        answer.push_back({ start, end });
        HanoiTop(answer, n - 1, bypass, end, start);
    }
}
