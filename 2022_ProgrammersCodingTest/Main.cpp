#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while (true)
    {
        set<pair<int, int>> s;

        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j + 1])
                {
                    s.emplace(i, j);
                    s.emplace(i + 1, j);
                    s.emplace(i, j + 1);
                    s.emplace(i + 1, j + 1);
                }
            }
        }

        if (s.empty())
        {
            break;
        }

        answer += s.size();

        for (const auto& p : s)
        {
            board[p.first][p.second] = ' ';
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (board[j][i] == ' ')
                {
                    for (int k = j - 1; k >= 0; --k)
                    {
                        if (board[k][i] != ' ')
                        {
                            board[j][i] = board[k][i];
                            board[k][i] = ' ';
                            break;
                        }
                    }

                    if (board[j][i] == ' ')
                    {
                        break;
                    }
                }
            }
        }
    }

    return answer;
}
