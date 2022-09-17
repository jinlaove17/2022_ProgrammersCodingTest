#include <string>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";
    string str = "";

    int space = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != ' ')
        {
            str.push_back(s[i]);
        }
        else
        {
            ++space;

            if (i < s.length() - 1 && s[i + 1] != ' ')
            {
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                str[0] = toupper(str[0]);

                answer += str;

                for (int i = 0; i < space; ++i)
                {
                    answer.push_back(' ');
                }

                str.clear();
                space = 0;
            }
        }
    }

    if (!str.empty())
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        str[0] = toupper(str[0]);
        answer += str;

        for (int i = 0; i < space; ++i)
        {
            answer.push_back(' ');
        }
    }

    return answer;
}
