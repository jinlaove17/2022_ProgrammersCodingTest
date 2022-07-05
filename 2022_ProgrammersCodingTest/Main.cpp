#include <string>

using namespace std;

string solution(string s)
{
    int length{ static_cast<int>(s.length()) };
    int centerPos{ length / 2 };

    string answer{};
    
    if (length <= 2)
    {
        answer = s;
    }
    else
    {
        if (length & 1)
        {
            answer = s[centerPos];
        }
        else
        {
            answer.push_back(s[centerPos - 1]);
            answer.push_back(s[centerPos]);
        }
    }

    return answer;
}

// string::substr을 사용하면 쉽게 해결할 수 있다.
