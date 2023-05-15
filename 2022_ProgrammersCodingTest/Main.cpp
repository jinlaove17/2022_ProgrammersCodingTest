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

    // 0 또한 당첨된 번호라고 생각하여 최고 순위 번호를 구한다.
    answer.push_back(((winCnt + cnt[0]) >= 1) ? 7 - (winCnt + cnt[0]) : 6);

    // 당첨된 번호의 개수로만 번호를 구하여 최저 순위 번호를 구한다.
    answer.push_back((winCnt >= 2) ? 7 - winCnt : 6);

    return answer;
}
