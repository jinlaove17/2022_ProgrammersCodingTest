#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    unordered_map<char, int> um;

    for (int i = 0; i < s.length(); ++i)
    {
        if (um.find(s[i]) == um.end())
        {
            um[s[i]] = i;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - um[s[i]]);
            um[s[i]] = i;
        }
    }

    return answer;
}
