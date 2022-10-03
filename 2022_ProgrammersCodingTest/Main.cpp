#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    vector<string> v;

    v.reserve(skill_trees.size());

    for (const auto& skill_tree : skill_trees)
    {
        string s;

        for (char c1 : skill_tree)
        {
            for (char c2 : skill)
            {
                if (c1 == c2)
                {
                    s.push_back(c1);
                    break;
                }
            }
        }

        v.push_back(s);
    }

    for (const string& s : v)
    {
        bool isValid = true;
        int len = s.length();

        for (int i = 0; i < len; ++i)
        {
            if (s[i] != skill[i])
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            ++answer;
        }
    }

    return answer;
}
