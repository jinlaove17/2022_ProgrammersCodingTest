#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void FindGroup(const vector<int>& cards, vector<int>& group, int groupIndex, int n);

int solution(vector<int> cards)
{
    int answer = 0;

    // 각 상자가 어떤 그룹에 속하는지 저장하는 변수
    vector<int> group(cards.size());

    // 그룹의 인덱스
    int groupIndex = 0;

    for (int i = 0; i < cards.size(); ++i)
    {
        // 아직 그룹이 정해지지 않은 상자라면, 그룹을 찾는다.
        if (group[cards[i] - 1] == 0)
        {
            // 여기에 들어올 경우, 매번 다른 그룹을 찾는 것이므로 그룹 인덱스를 증가시켜주어야 한다.
            FindGroup(cards, group, ++groupIndex, cards[i] - 1);
        }
    }

    vector<int> boxCnt(cards.size());

    // 각 그룹의 상자 수를 구한다.
    for (int i = 0; i < group.size(); ++i)
    {
        ++boxCnt[group[i] - 1];
    }

    // 상자수를 내림차순으로 정렬한다.
    sort(boxCnt.begin(), boxCnt.end(), greater<>());

    // 그룹이 2종류 이상일 때는 그룹별로 상자수를 곱해준다.
    // 가장 많은 상자수가 모든 상자수보다 작으면 2종류 이상이라는 것을 알 수 있다.
    if (boxCnt[0] < cards.size())
    {
        answer = boxCnt[0] * boxCnt[1];
    }

    return answer;
}

void FindGroup(const vector<int>& cards, vector<int>& group, int groupIndex, int n)
{
    group[n] = groupIndex;

    if (group[cards[n] - 1] == 0)
    {
        FindGroup(cards, group, groupIndex, cards[n] - 1);
    }
}
