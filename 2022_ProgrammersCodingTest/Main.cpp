#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void DFS(const vector<vector<string>>& relation, const vector<string>& partRelation, vector<string>& combinations, const string& indices, int index);
bool CheckUniqueness(const vector<string>& partRelation);
bool CheckMinimality(const string& standard, const string& str);

int solution(vector<vector<string>> relation)
{
    int answer = 0;

    // ��ȿ���� �����ϴ� �κ� �����̼� ������ �ε���
    vector<string> combinations;

    for (int i = 0; i < relation[0].size(); ++i)
    {
        // �ϳ��� �Ӽ����θ� ������ �κ� �����̼��� �����.
        vector<string> partRelation;

        for (int j = 0; j < relation.size(); ++j)
        {
            partRelation.push_back(relation[j][i]);
        }

        DFS(relation, partRelation, combinations, to_string(i), i);
    }

    // ���̸� �������� �������� �����Ѵ�.
    // ����, ���̰� ���ٸ� �� ���ڸ� �������� �������� �����Ѵ�.
    sort(combinations.begin(), combinations.end(),
        [](const auto& a, const auto& b)
        {
            if (a.length() == b.length())
            {
                return a < b;
            }

            return a.length() < b.length();
        });

    // combinations�� ��� ���ҵ��� ���ϸ�, ������ �Ǵ� ���ҿ� ���� ������ ������ ������ �Ǵ� ������ ���̿� ���ٸ� �ּҼ��� �������� ���ϹǷ� �����̳ʿ��� �����Ѵ�.
    for (auto iter1 = combinations.begin(); iter1 != combinations.end(); ++iter1)
    {
        for (auto iter2 = iter1 + 1; iter2 != combinations.end(); )
        {
            if (CheckMinimality(*iter1, *iter2))
            {
                ++iter2;
            }
            else
            {
                iter2 = combinations.erase(iter2);
            }
        }
    }

    // combinations�� ���� ���ҵ��� ���ϼ��� �ּҼ��� �����ϴ� ���� �ĺ�Ű�� �ȴ�.
    answer = combinations.size();

    return answer;
}

void DFS(const vector<vector<string>>& relation, const vector<string>& partRelation, vector<string>& combinations, const string& indices, int index)
{
    // ���ϼ��� �����ϴ��� �˻��ϰ�, ������ ��� combinations�� �߰��Ѵ�.
    // ���� �� �����̼ǰ��� ������ �ּҼ��� �������� ���ϹǷ� return�Ѵ�.
    if (CheckUniqueness(partRelation))
    {
        combinations.push_back(indices);
        return;
    }

    for (int i = index + 1; i < relation[0].size(); ++i)
    {
        vector<string> newPartRelation(partRelation);

        // ������ �κ� �����̼�(partRelation)�� ���ο� �Ӽ��� ���� ���ο� �κ� �����̼��� �����.
        for (int j = 0; j < relation.size(); ++j)
        {
            newPartRelation[j] += ' ' + relation[j][i];
        }

        DFS(relation, newPartRelation, combinations, indices + to_string(i), i);
    }
}

bool CheckUniqueness(const vector<string>& partRelation)
{
    bool isUniqueness = true;
    unordered_set<string> s;

    for (const string& str : partRelation)
    {
        if (s.find(str) == s.end())
        {
            s.insert(str);
        }
        else
        {
            isUniqueness = false;
            break;
        }
    }

    return isUniqueness;
}

bool CheckMinimality(const string& standard, const string& str)
{
    bool isMinimality = true;
    int sameCnt = 0;

    for (char c : standard)
    {
        if (str.find(c) != string::npos)
        {
            ++sameCnt;
        }
    }

    if (standard.length() == sameCnt)
    {
        isMinimality = false;
    }

    return isMinimality;
}
