#include <string>

using namespace std;

bool solution(string s)
{
    bool answer{};
    int length{ static_cast<int>(s.length()) };

    if (length == 4 || length == 6)
    {
        answer = true;

        for (char c : s)
        {
            if (!isdigit(c))
            {
                answer = false;
                break;
            }
        }
    }

    return answer;
}
