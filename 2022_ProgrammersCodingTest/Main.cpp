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
        // 종료 시각을 기준으로 내림차순으로 정렬한다.(top은 제일 종료 시각이 빠른 시간)
        return a.second > b.second;
    }
};

int solution(vector<vector<string>> book_time)
{
    int answer = 0;

    // 시작 시각을 기준으로 오름차순으로 정렬한다.
    sort(book_time.begin(), book_time.end(),
        [](const auto& a, const auto& b)
        {
            return a[0] < b[0];
        });

    // 우선순위 큐(분 단위)
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    // book_time을 순회하며, 우선순위 큐에 추가한다.
    // 이때, 매번 큐의 사이즈를 체크하여 최대값을 갱신해준다.
    for (const auto& v : book_time)
    {
        // 입실할 방의 시각
        int inBeginMin = 60 * stoi(v[0].substr(0, 2)) + stoi(v[0].substr(3, 2));
        int inEndMin = 60 * stoi(v[1].substr(0, 2)) + stoi(v[1].substr(3, 2));

        // 큐가 비어있다면, 바로 추가한다.
        if (pq.empty())
        {
            pq.emplace(inBeginMin, inEndMin);
        }
        else
        {
            // 입실한 방 중 가장 임박한 종료 시각(청소 시간 10분 포함)
            int lastEndMin = pq.top().second + 10;

            // 우선은 큐에 추가한다.
            pq.emplace(inBeginMin, inEndMin);

            // 입실한 방의 종료 시각이 더 빨랐다면, 큐에서 제거하여 이 방에 추가한 것으로 간주한다.
            if (lastEndMin <= inBeginMin)
            {
                pq.pop();
            }
        }

        answer = max(answer, static_cast<int>(pq.size()));
    }

    return answer;
}
