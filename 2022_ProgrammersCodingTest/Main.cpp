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

    // 로봇의 처음 위치(R)와 목표 지점(G)의 좌표를 구한다.
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

    // 풀이를 간단히 하기 위해 맵(board)의 시작점과 도착점 또한 '.'으로 변경한다.
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

        // 목표 지점(G)에 도착했다면, 반복문을 빠져나간다.
        if ((current.x == ex) && (current.y == ey))
        {
            return current.dist;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = current.x;
            int ny = current.y;

            // 현재 위치(current.x, current.y)에서 장애물에 다다르거나 맵의 끝에 도달할 때까지 계속해서 (dirX[i], dirY[i])씩 이동한다.
            while ((0 <= nx + dirX[i]) && (nx + dirX[i] < maxCol) &&
                   (0 <= ny + dirY[i]) && (ny + dirY[i] < maxRow) &&
                   (board[ny + dirY[i]][nx + dirX[i]] == '.'))
            {
                nx += dirX[i];
                ny += dirY[i];
            }

            // 만약 해당 위치가 방문하지 않았던 위치라면, 큐에 추가한다.
            if (!isVisited[ny][nx])
            {
                isVisited[ny][nx] = true;
                q.push({ nx, ny, current.dist + 1 });
            }
        }
    }

    return -1;
}
