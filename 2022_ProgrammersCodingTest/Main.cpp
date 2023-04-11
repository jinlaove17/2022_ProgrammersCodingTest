#include <vector>

using namespace std;

void Rotate(vector<vector<int>>& board, int x1, int y1, int x2, int y2, int x, int y, int& minValue);

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1));
    int num = 1;

    for (int r = 1; r <= rows; ++r)
    {
        for (int c = 1; c <= columns; ++c)
        {
            board[r][c] = num++;
        }
    }

    for (const auto& query : queries)
    {
        int x1 = query[0], y1 = query[1], x2 = query[2], y2 = query[3];
        int temp = board[x1 + 1][y1];
        int minValue = temp;

        Rotate(board, x1, y1, x2, y2, x1, y1 + 1, minValue);
        board[x1][y1] = temp;

        answer.push_back(minValue);
    }

    return answer;
}

void Rotate(vector<vector<int>>& board, int x1, int y1, int x2, int y2, int x, int y, int& minValue)
{
    if (x == x1 && y == y1)
    {
        return;
    }

    int temp = 0;

    if (x == x1)
    {
        temp = board[x][y - 1];

        if (y < y2)
        {
            Rotate(board, x1, y1, x2, y2, x, y + 1, minValue);
        }
        else
        {
            Rotate(board, x1, y1, x2, y2, x + 1, y, minValue);
        }

        board[x][y] = temp;
        minValue = min(minValue, temp);
    }
    else if (y == y2)
    {
        temp = board[x - 1][y];

        if (x < x2)
        {
            Rotate(board, x1, y1, x2, y2, x + 1, y, minValue);
        }
        else
        {
            Rotate(board, x1, y1, x2, y2, x, y - 1, minValue);
        }

        board[x][y] = temp;
        minValue = min(minValue, temp);
    }
    else if (x == x2)
    {
        temp = board[x][y + 1];

        if (y > y1)
        {
            Rotate(board, x1, y1, x2, y2, x, y - 1, minValue);
        }
        else
        {
            Rotate(board, x1, y1, x2, y2, x - 1, y, minValue);
        }

        board[x][y] = temp;
        minValue = min(minValue, temp);
    }
    else if (y == y1)
    {
        temp = board[x + 1][y];

        if (x > x1)
        {
            Rotate(board, x1, y1, x2, y2, x - 1, y, minValue);
        }

        board[x][y] = temp;
        minValue = min(minValue, temp);
    }
}
