#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void FindGroup(const vector<int>& cards, vector<int>& group, int groupIndex, int n);

int solution(vector<int> cards)
{
    int answer = 0;

    // �� ���ڰ� � �׷쿡 ���ϴ��� �����ϴ� ����
    vector<int> group(cards.size());

    // �׷��� �ε���
    int groupIndex = 0;

    for (int i = 0; i < cards.size(); ++i)
    {
        // ���� �׷��� �������� ���� ���ڶ��, �׷��� ã�´�.
        if (group[cards[i] - 1] == 0)
        {
            // ���⿡ ���� ���, �Ź� �ٸ� �׷��� ã�� ���̹Ƿ� �׷� �ε����� ���������־�� �Ѵ�.
            FindGroup(cards, group, ++groupIndex, cards[i] - 1);
        }
    }

    vector<int> boxCnt(cards.size());

    // �� �׷��� ���� ���� ���Ѵ�.
    for (int i = 0; i < group.size(); ++i)
    {
        ++boxCnt[group[i] - 1];
    }

    // ���ڼ��� ������������ �����Ѵ�.
    sort(boxCnt.begin(), boxCnt.end(), greater<>());

    // �׷��� 2���� �̻��� ���� �׷캰�� ���ڼ��� �����ش�.
    // ���� ���� ���ڼ��� ��� ���ڼ����� ������ 2���� �̻��̶�� ���� �� �� �ִ�.
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
