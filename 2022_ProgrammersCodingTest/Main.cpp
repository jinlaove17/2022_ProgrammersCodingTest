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

    // 유효성을 만족하는 부분 릴레이션 조합의 인덱스
    vector<string> combinations;

    for (int i = 0; i < relation[0].size(); ++i)
    {
        // 하나의 속성으로만 구성된 부분 릴레이션을 만든다.
        vector<string> partRelation;

        for (int j = 0; j < relation.size(); ++j)
        {
            partRelation.push_back(relation[j][i]);
        }

        DFS(relation, partRelation, combinations, to_string(i), i);
    }

    // 길이를 기준으로 오름차순 정렬한다.
    // 만약, 길이가 같다면 각 문자를 기준으로 오름차순 정렬한다.
    sort(combinations.begin(), combinations.end(),
        [](const auto& a, const auto& b)
        {
            if (a.length() == b.length())
            {
                return a < b;
            }

            return a.length() < b.length();
        });

    // combinations의 모든 원소들을 비교하며, 기준이 되는 원소와 같은 문자의 개수가 기준이 되는 원소의 길이와 같다면 최소성을 만족하지 못하므로 컨테이너에서 삭제한다.
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

    // combinations에 남은 원소들이 유일성과 최소성을 만족하는 최종 후보키가 된다.
    answer = combinations.size();

    return answer;
}

void DFS(const vector<vector<string>>& relation, const vector<string>& partRelation, vector<string>& combinations, const string& indices, int index)
{
    // 유일성을 만족하는지 검사하고, 만족할 경우 combinations에 추가한다.
    // 이후 이 릴레이션과의 조합은 최소성을 만족하지 못하므로 return한다.
    if (CheckUniqueness(partRelation))
    {
        combinations.push_back(indices);
        return;
    }

    for (int i = index + 1; i < relation[0].size(); ++i)
    {
        vector<string> newPartRelation(partRelation);

        // 기존의 부분 릴레이션(partRelation)에 새로운 속성을 더해 새로운 부분 릴레이션을 만든다.
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
