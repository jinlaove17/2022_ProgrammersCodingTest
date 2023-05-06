#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator ()(const pair<int, int>& a, const pair<int, int>& b)
    {
        // ���� �ð��� �������� ������������ �����Ѵ�.(top�� ���� ���� �ð��� ���� �ð�)
        return a.second > b.second;
    }
};

int solution(vector<vector<string>> book_time)
{
    int answer = 0;

    // ���� �ð��� �������� ������������ �����Ѵ�.
    sort(book_time.begin(), book_time.end(),
        [](const auto& a, const auto& b)
        {
            return a[0] < b[0];
        });

    // �켱���� ť(�� ����)
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    // book_time�� ��ȸ�ϸ�, �켱���� ť�� �߰��Ѵ�.
    // �̶�, �Ź� ť�� ����� üũ�Ͽ� �ִ밪�� �������ش�.
    for (const auto& v : book_time)
    {
        // �Խ��� ���� �ð�
        int inBeginMin = 60 * stoi(v[0].substr(0, 2)) + stoi(v[0].substr(3, 2));
        int inEndMin = 60 * stoi(v[1].substr(0, 2)) + stoi(v[1].substr(3, 2));

        // ť�� ����ִٸ�, �ٷ� �߰��Ѵ�.
        if (pq.empty())
        {
            pq.emplace(inBeginMin, inEndMin);
        }
        else
        {
            // �Խ��� �� �� ���� �ӹ��� ���� �ð�(û�� �ð� 10�� ����)
            int lastEndMin = pq.top().second + 10;

            // �켱�� ť�� �߰��Ѵ�.
            pq.emplace(inBeginMin, inEndMin);

            // �Խ��� ���� ���� �ð��� �� �����ٸ�, ť���� �����Ͽ� �� �濡 �߰��� ������ �����Ѵ�.
            if (lastEndMin <= inBeginMin)
            {
                pq.pop();
            }
        }

        answer = max(answer, static_cast<int>(pq.size()));
    }

    return answer;
}
