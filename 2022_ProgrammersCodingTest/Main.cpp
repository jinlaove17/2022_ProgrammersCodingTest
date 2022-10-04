#include <string>
#include <vector>

using namespace std;

struct USED_DIR
{
    bool up;
    bool down;
    bool left;
    bool right;
};

int solution(string dirs)
{
    int answer = 0;

    int size = 5 - (-5) + 1;
    vector<vector<USED_DIR>> usedDirs(size);

    for (int i = 0; i < size; ++i)
    {
        usedDirs[i].resize(size);
    }

    int x = 5;
    int y = 5;

    for (char dir : dirs)
    {
        // 테스트 케이스 8번 이후로 다틀림 ?
        // => 지나간 길에는 방향성이 존재하지 않음!
        switch (dir)
        {
        case 'U':
            if (y - 1 >= 0)
            {
                if (!usedDirs[y][x].up)
                {
                    usedDirs[y][x].up = usedDirs[y - 1][x].down = true;
                    ++answer;
                }

                --y;
            }
            break;
        case 'D':
            if (y + 1 < size)
            {
                if (!usedDirs[y][x].down)
                {
                    usedDirs[y][x].down = usedDirs[y + 1][x].up = true;
                    ++answer;
                }

                ++y;
            }
            break;
        case 'L':
            if (x - 1 >= 0)
            {
                if (!usedDirs[y][x].left)
                {
                    usedDirs[y][x].left = usedDirs[y][x - 1].right = true;
                    ++answer;
                }

                --x;
            }
            break;
        case 'R':
            if (x + 1 < size)
            {
                if (!usedDirs[y][x].right)
                {
                    usedDirs[y][x].right = usedDirs[y][x + 1].left = true;
                    ++answer;
                }

                ++x;
            }
            break;
        }
    }

    return answer;
}
