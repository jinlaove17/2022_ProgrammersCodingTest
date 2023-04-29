#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer, cnt(N + 1);

    // �� ���������� ���������� ���� Ŭ�������� ���� �÷��̾��� ���� ���Ѵ�.
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

        // �� �÷��̾��� ������ ���� �ܰ迡 ���޸��� �÷��̾� ����ŭ ����.
        totalPlayer -= cnt[i];
    }

    sort(v.begin(), v.end(),
        [](const auto& p1, const auto& p2)
        {
            // �������� ���� ��쿡�� ���������� �������� ������������ ������ �����Ѵ�.
            if (p1.second == p2.second)
            {
                return p1.first < p2.first;
            }

            // �������� �������� ������������ ������ �����Ѵ�.   
            return p1.second > p2.second;
        });

    for (const auto& p : v)
    {
        answer.push_back(p.first);
    }

    return answer;
}
