#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;

    int dist;
};

int BFS(const vector<string>& board, int sx, int sy, int ex, int ey);

int solution(vector<string> board)
{
    int answer = 0;

    // �κ��� ó�� ��ġ(R)�� ��ǥ ����(G)�� ��ǥ�� ���Ѵ�.
    int sx = 0, sy = 0, ex = 0, ey = 0;

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[0].size(); ++x)
        {
            switch (board[y][x])
            {
            case 'R':
                sx = x;
                sy = y;
                break;
            case 'G':
                ex = x;
                ey = y;
                break;
            }
        }
    }

    // Ǯ�̸� ������ �ϱ� ���� ��(board)�� �������� ������ ���� '.'���� �����Ѵ�.
    board[sy][sx] = board[ey][ex] = '.';
    answer = BFS(board, sx, sy, ex, ey);

    return answer;
}

int BFS(const vector<string>& board, int sx, int sy, int ex, int ey)
{
    int maxRow = board.size();
    int maxCol = board.front().size();
    int dirX[] = { 0, 0, -1, 1 };
    int dirY[] = { -1, 1, 0, 0 };

    vector<vector<bool>> isVisited(maxRow, vector<bool>(maxCol));
    queue<Node> q;

    isVisited[sy][sx] = true;
    q.push({ sx, sy, 0 });

    while (!q.empty())
    {
        Node current = q.front();

        q.pop();

        // ��ǥ ����(G)�� �����ߴٸ�, �ݺ����� ����������.
        if ((current.x == ex) && (current.y == ey))
        {
            return current.dist;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = current.x;
            int ny = current.y;

            // ���� ��ġ(current.x, current.y)���� ��ֹ��� �ٴٸ��ų� ���� ���� ������ ������ ����ؼ� (dirX[i], dirY[i])�� �̵��Ѵ�.
            while ((0 <= nx + dirX[i]) && (nx + dirX[i] < maxCol) &&
                   (0 <= ny + dirY[i]) && (ny + dirY[i] < maxRow) &&
                   (board[ny + dirY[i]][nx + dirX[i]] == '.'))
            {
                nx += dirX[i];
                ny += dirY[i];
            }

            // ���� �ش� ��ġ�� �湮���� �ʾҴ� ��ġ���, ť�� �߰��Ѵ�.
            if (!isVisited[ny][nx])
            {
                isVisited[ny][nx] = true;
                q.push({ nx, ny, current.dist + 1 });
            }
        }
    }

    return -1;
}
