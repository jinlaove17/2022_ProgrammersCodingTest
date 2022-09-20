#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2, 0);

    // ���� ����������
    // (1) 2w + 2h - 4 = brown
    // (2) w * h = brown + yellow
    // (1)���� h = brown / 2 - w + 2
    // ����, w * (brown / 2 - w + 2) = brown + yellow
    int size = brown + yellow;

    // brown�� �ּ� 8�� �̻��̱� ������ ���ΰ� �ּ� 3�̻�, �ִ� 2500�����̴�.
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
