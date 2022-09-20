#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2, 0);

    // 이차 연립방정식
    // (1) 2w + 2h - 4 = brown
    // (2) w * h = brown + yellow
    // (1)에서 h = brown / 2 - w + 2
    // 따라서, w * (brown / 2 - w + 2) = brown + yellow
    int size = brown + yellow;

    // brown은 최소 8개 이상이기 때문에 가로가 최소 3이상, 최대 2500이하이다.
    for (int w = 3; w <= 2500; ++w)
    {
        int h = (brown / 2 - w + 2);

        if (w * h == size)
        {
            answer[0] = w;
            answer[1] = h;
        }
    }

    return answer;
}
