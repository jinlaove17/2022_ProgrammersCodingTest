#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    unordered_map<string, list<string>> um;

    sort(tickets.begin(), tickets.end(), greater<vector<string>>());

    for (const auto& ticket : tickets)
    {
        um[ticket[0]].push_back(ticket[1]);
    }

    stack<string> s({ "ICN" });

    while (!s.empty())
    {
        string current = s.top();

        if (um.count(current) == 0 || um[current].empty())
        {
            s.pop();
            answer.push_back(current);
        }
        else
        {
            s.push(um[current].back());
            um[current].pop_back();
        }
    }

    // 현재 answer에는 역순으로 여행경로가 저장되어 있기 때문에, 벡터를 뒤집는다.
    reverse(answer.begin(), answer.end());

    return answer;
}
