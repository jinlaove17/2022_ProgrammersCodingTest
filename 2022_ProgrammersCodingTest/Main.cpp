#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;

    map<string, int> m;
    int index = 26;

    for (int i = 1; i <= index; ++i)
    {
        m[string(1, 'A' + (i - 1))] = i;
    }

    int len = msg.length();

    for (int i = 0; i < len; ++i)
    {
        string s;
        int j = i;

        for (; j < len; ++j)
        {
            s.push_back(msg[j]);

            if (m.count(s) == 0)
            {
                m[s] = ++index;
                break;
            }
        }

        answer.push_back(m[s.substr(0, j - i)]);
        i += (j - i - 1);
    }

    return answer;
}
