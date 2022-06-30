#include <string>

using namespace std;

string solution(string s, int n)
{
    int length{ static_cast<int>(s.length()) };
    string answer{};

    answer.reserve(length);

    for (int i = 0; i < length; ++i)
    {
        if (s[i] == ' ')
        {
            answer.push_back(' ');
        }
        else if (isupper(s[i]))
        {
            answer.push_back(65 + (s[i] % 65 + n) % 26);
        }
        else if (islower(s[i]))
        {
            answer.push_back(97 + (s[i] % 97 + n) % 26);
        }
    }

    return answer;
}
