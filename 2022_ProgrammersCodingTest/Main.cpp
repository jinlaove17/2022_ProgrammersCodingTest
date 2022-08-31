#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int maxLength = 0;

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (i > 0 && j > 0 && board[i][j] > 0)
            {
                board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
            }

            if (board[i][j] > maxLength)
            {
                maxLength = board[i][j];
            }
        }
    }

    answer = pow(maxLength, 2);

    return answer;
}

// 참고 : https://ansohxxn.github.io/programmers/85/
// DP를 이용한 풀이법
