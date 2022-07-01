#include <string>

using namespace std;

bool solution(string s)
{
    bool answer{};

    int countP{};
    int countY{};

    for (char c : s)
    {
        if (c == 'p' || c == 'P')
        {
            countP += 1;
        }
        else if (c == 'y' || c == 'Y')
        {
            countY += 1;
        }
    }

    if (countP == countY)
    {
        answer = true;
    }

    return answer;
}
