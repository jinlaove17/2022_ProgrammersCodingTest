#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer, cnt(N + 1);

    // 각 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수를 구한다.
    for (int stage : stages)
    {
        ++cnt[stage];
    }

    // <index, failRatio>
    vector<pair<int, float>> v;
    int totalPlayer = stages.size();

    for (int i = 1; i <= N; ++i)
    {
        if (cnt[i] == 0)
        {
            v.emplace_back(i, 0.0f);
        }
        else
        {
            float failRatio = static_cast<float>(cnt[i]) / totalPlayer;

            v.emplace_back(i, failRatio);
        }

        // 총 플레이어의 수에서 현재 단계에 도달만한 플레이어 수만큼 뺀다.
        totalPlayer -= cnt[i];
    }

    sort(v.begin(), v.end(),
        [](const auto& p1, const auto& p2)
        {
            // 실패율이 같을 경우에는 스테이지를 기준으로 오름차순으로 정렬을 수행한다.
            if (p1.second == p2.second)
            {
                return p1.first < p2.first;
            }

            // 실패율을 기준으로 내림차순으로 정렬을 수행한다.   
            return p1.second > p2.second;
        });

    for (const auto& p : v)
    {
        answer.push_back(p.first);
    }

    return answer;
}
