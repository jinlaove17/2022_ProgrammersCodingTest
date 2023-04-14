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

    // �ֹ��� �޴���� ���� ������������ ���Ľ�Ų��.
    for (int i = 0; i < orders.size(); ++i)
    {
        sort(orders[i].begin(), orders[i].end());
    }

    // ��� �ֹ��� ��ȸ�ϸ�, ���� �� �ִ� 2���� �̻��� ������ ������ ���Ѵ�.
    for (int i = 0; i < orders.size(); ++i)
    {
        for (int j = 0; j < orders[i].size(); ++j)
        {
            DFS(course, orders[i], string(1, orders[i][j]), j);
        }
    }

    // ���� ������ �ִ� ������ ���ٸ� answer�� �߰��Ѵ�.
    // �̶�, �ּ� 2�� �̻��� �մ����κ��� �ֹ��� ��ǰ�޴� ���տ� ���ؼ��� �ڽ��丮 �޴� �ĺ��� �����Ѵ�.
    for (auto iter = counts.begin(); iter != counts.end(); ++iter)
    {
        if ((iter->second >= 2) && (iter->second == maxCounts[iter->first.length()]))
        {
            answer.push_back(iter->first);
        }
    }

    // ������������ �����Ѵ�.
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
