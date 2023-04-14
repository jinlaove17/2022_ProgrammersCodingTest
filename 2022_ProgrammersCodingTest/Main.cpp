#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> counts;
int maxCounts[11]; // index: length

void DFS(const vector<int>& course, const string& s, string current, int idx);

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    // 주문한 메뉴목록 또한 오름차순으로 정렬시킨다.
    for (int i = 0; i < orders.size(); ++i)
    {
        sort(orders[i].begin(), orders[i].end());
    }

    // 모든 주문을 순회하며, 만들 수 있는 2글자 이상의 조합의 개수를 구한다.
    for (int i = 0; i < orders.size(); ++i)
    {
        for (int j = 0; j < orders[i].size(); ++j)
        {
            DFS(course, orders[i], string(1, orders[i][j]), j);
        }
    }

    // 구한 개수가 최대 개수와 같다면 answer에 추가한다.
    // 이때, 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함한다.
    for (auto iter = counts.begin(); iter != counts.end(); ++iter)
    {
        if ((iter->second >= 2) && (iter->second == maxCounts[iter->first.length()]))
        {
            answer.push_back(iter->first);
        }
    }

    // 오름차순으로 정렬한다.
    sort(answer.begin(), answer.end());

    return answer;
}

void DFS(const vector<int>& course, const string& s, string current, int idx)
{
    if (find(course.begin(), course.end(), current.length()) != course.end())
    {
        maxCounts[current.length()] = max(maxCounts[current.length()], ++counts[current]);
    }

    for (int i = idx + 1; i < s.length(); ++i)
    {
        DFS(course, s, current + s[i], i);
    }
}
