#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    vector<int> wall(n + 1, 1);

    // 칠해야 할 벽의 부분은 0으로 초기화한다.
    for (int i = 0; i < section.size(); ++i)
    {
        wall[section[i]] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        // 칠해야 할 벽의 부분이라면,
        if (wall[i] == 0)
        {
            // 롤러의 길이만큼 벽을 오른쪽으로 칠한다.
            i = i + m - 1;

            // 페인트 칠 횟수를 1 증가시킨다.
            ++answer;
        }
    }

    return answer;
}
