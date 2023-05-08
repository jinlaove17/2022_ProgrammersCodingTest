#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0;

    // minerals를 5개씩 나누어, 시작 인덱스와 광물의 합산 가치를 구한다.
    // diamond: +100, iron: +10, stone: +1
    // <index, totalValue>
    vector<pair<int, int>> values;
    int totalPick = picks[0] + picks[1] + picks[2];

    for (int i = 0; i < minerals.size(); i += 5)
    {
        // 곡괭이의 총 개수를 넘어가지 않도록 섹션을 만들어야 한다.
        if (values.size() == totalPick)
        {
            break;
        }

        int value = 0;

        for (int j = i; j < i + 5; ++j)
        {
            // 인덱스를 벗어날 경우, 내부 반복문을 빠져나간다.
            if (j >= minerals.size())
            {
                break;
            }

            if (minerals[j] == "diamond")
            {
                value += 100;
            }
            else if (minerals[j] == "iron")
            {
                value += 10;
            }
            else
            {
                value += 1;
            }
        }

        // 시작 인덱스와, 합산 가치를 벡터에 추가한다.
        values.push_back({ i, value });
    }

    // 합산 가치를 기준으로 내림차순 정렬한다.
    sort(values.begin(), values.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    // 각 섹션의 피로도를 계산한다.
    for (int i = 0; i < values.size(); ++i)
    {
        int pickIdx = -1;

        // 곡괭이는 피로도가 적게 올라가는 diamond -> iron -> stone 순으로 사용한다.
        if (picks[0] > 0)
        {
            pickIdx = 0;
        }
        else if (picks[1] > 0)
        {
            pickIdx = 1;
        }
        else
        {
            pickIdx = 2;
        }

        // 사용한 곡괭이의 개수를 감소시킨다.
        --picks[pickIdx];

        // 저장해둔 시작 인덱스부터 시작하여 5개를 캐는데 소모되는 피로도를 계산한다.
        for (int j = values[i].first; j < values[i].first + 5; ++j)
        {
            if (j >= minerals.size())
            {
                break;
            }

            if (minerals[j] == "diamond")
            {
                switch (pickIdx)
                {
                case 0:
                    answer += 1;
                    break;
                case 1:
                    answer += 5;
                    break;
                case 2:
                    answer += 25;
                    break;
                }
            }
            else if (minerals[j] == "iron")
            {
                switch (pickIdx)
                {
                case 0:
                case 1:
                    answer += 1;
                    break;
                case 2:
                    answer += 5;
                    break;
                }
            }
            else
            {
                answer += 1;
            }
        }
    }

    return answer;
}
