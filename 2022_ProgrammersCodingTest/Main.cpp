#include <string>
#include <climits>

using namespace std;

int solution(string s)
{
    int answer = INT_MAX;

    for (int len = 1; len <= s.length(); ++len)
    {
        string str, last, temp;

        temp = last = s.substr(0, len);

        for (int i = len; i <= s.length(); i += len)
        {
            string current = s.substr(i, len);

            if (current == last)
            {
                temp += last;
            }
            else
            {
                int cnt = temp.length() / len;

                if (cnt > 1)
                {
                    str += to_string(cnt);
                }

                str += last;
                temp = last = current;
            }
        }

        int cnt = temp.length() / len;

        if (cnt > 1)
        {
            str += to_string(cnt);
        }

        str += last;
        answer = min(answer, static_cast<int>(str.length()));
    }

    return answer;
}
