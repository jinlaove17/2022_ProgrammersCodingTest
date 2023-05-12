#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;

    sort(data.begin(), data.end(),
        [col](const auto& a, const auto& b)
        {
            // col 번째 컬럼이 같을 경우,
            if (a[col - 1] == b[col - 1])
            {
                // 기본키인 첫 번째 컬럼의 값을 기준으로 내림차순 정렬한다.
                return a[0] > b[0];
            }

            // 그 외에는 col 번째 컬럼을 기준으로 오름차순 정렬한다.
            return a[col - 1] < b[col - 1];
        });

    // si를 계산한다.
    for (int i = row_begin - 1; i < row_end; ++i)
    {
        int si = 0;

        for (int j = 0; j < data[i].size(); ++j)
        {
            si += data[i][j] % (i + 1);
        }

        // XOR(^): 같으면 0, 다르면 1
        // answer의 초기 값은 0이기 때문에, 어떤 수 n과 XOR 연산을 수행하더라도 결과 값은 오로지 n의 값에 의해서만 결정된다.
        answer ^= si;
    }

    return answer;
}
