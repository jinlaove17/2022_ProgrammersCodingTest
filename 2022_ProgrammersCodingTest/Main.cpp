#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;

    sort(data.begin(), data.end(),
        [col](const auto& a, const auto& b)
        {
            // col ��° �÷��� ���� ���,
            if (a[col - 1] == b[col - 1])
            {
                // �⺻Ű�� ù ��° �÷��� ���� �������� �������� �����Ѵ�.
                return a[0] > b[0];
            }

            // �� �ܿ��� col ��° �÷��� �������� �������� �����Ѵ�.
            return a[col - 1] < b[col - 1];
        });

    // si�� ����Ѵ�.
    for (int i = row_begin - 1; i < row_end; ++i)
    {
        int si = 0;

        for (int j = 0; j < data[i].size(); ++j)
        {
            si += data[i][j] % (i + 1);
        }

        // XOR(^): ������ 0, �ٸ��� 1
        // answer�� �ʱ� ���� 0�̱� ������, � �� n�� XOR ������ �����ϴ��� ��� ���� ������ n�� ���� ���ؼ��� �����ȴ�.
        answer ^= si;
    }

    return answer;
}
