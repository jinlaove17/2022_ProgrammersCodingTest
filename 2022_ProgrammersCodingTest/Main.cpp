#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    string str;
    unordered_map<int, int> um;

    for (char c : s)
    {
        if ('0' <= c && c <= '9')
        {
            str.push_back(c);
        }
        else if (c == ',' || c == '}')
        {
            if (!str.empty())
            {
                ++um[atoi(str.c_str())];
                str.clear();
            }
        }
    }

    while (!um.empty())
    {
        auto iter = max_element(um.begin(), um.end(), [](auto& a, auto& b) {
            return a.second < b.second;
            });

        answer.push_back(iter->first);
        um.erase(iter);
    }

    return answer;
}
