#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    unordered_map<string, int> str1Group;
    int len = str1.length();

    // str1에 속한 문자들을 순회하며, 두 글자로 된 다중집합을 만든다.
    for (int i = 0; i < len - 1; ++i)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            ++str1Group[str1.substr(i, 2)];
        }
    }

    unordered_map<string, int> str2Group;

    len = str2.length();

    // str2에 속한 문자들을 순회하며, 두 글자로 된 다중집합을 만든다.
    for (int i = 0; i < len - 1; ++i)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            ++str2Group[str2.substr(i, 2)];
        }
    }

    int unionCount = 0;
    int intersectionCount = 0;

    // str1 다중집합을 순회하며, 합집합 수, 교집합 수를 계산한다.
    for (const auto& p : str1Group)
    {
        int count = str2Group.count(p.first);

        if (count > 0)
        {
            intersectionCount += min(p.second, str2Group[p.first]);
            unionCount += max(p.second, str2Group[p.first]);

            str2Group.erase(p.first);
        }
        else
        {
            unionCount += p.second;
        }
    }

    // str2 다중집합을 순회하며, 나머지 원소들을 합집합 수에 추가한다.
    for (const auto& p : str2Group)
    {
        unionCount += p.second;
    }

    float analogousMap = (unionCount == 0) ? 1 : static_cast<float>(intersectionCount) / unionCount;

    answer = 65536 * analogousMap;

    return answer;
}
