#include <string>

using namespace std;

int solution(string s)
{
    int answer{};

    if (s[0] == '-')
    {
        string onlyNum{ s.begin() + 1, s.end() };

        answer = -stoi(onlyNum);
    }
    else
    {
        answer = stoi(s);
    }

    return answer;
}

// 정보 : stoi는 부호처리를 따로 해줄 필요가 없다...
