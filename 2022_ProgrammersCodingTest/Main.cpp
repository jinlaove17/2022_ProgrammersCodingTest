#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    unordered_map<int, int> cnt;

    for (int n : lottos)
    {
        ++cnt[n];
    }

    int winCnt = 0;

    for (int n : win_nums)
    {
        if (cnt.find(n) != cnt.end())
        {
            ++winCnt;
        }
    }

    // 0 ���� ��÷�� ��ȣ��� �����Ͽ� �ְ� ���� ��ȣ�� ���Ѵ�.
    answer.push_back(((winCnt + cnt[0]) >= 1) ? 7 - (winCnt + cnt[0]) : 6);

    // ��÷�� ��ȣ�� �����θ� ��ȣ�� ���Ͽ� ���� ���� ��ȣ�� ���Ѵ�.
    answer.push_back((winCnt >= 2) ? 7 - winCnt : 6);

    return answer;
}
