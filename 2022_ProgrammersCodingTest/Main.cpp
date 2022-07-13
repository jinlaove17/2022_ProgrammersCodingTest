#include <string>

using namespace std;

string solution(string s)
{
    int length{ static_cast<int>(s.length()) };
    int pos{};

    for (int i = 0; i < length; ++i)
    {
        if (s[i] == ' ')
        {
            pos = 0;
            continue;
        }

        if (pos & 1)
        {
            s[i] = tolower(s[i]);
        }
        else
        {
            s[i] = toupper(s[i]);
        }

        pos += 1;
    }
    
    return s;
}
