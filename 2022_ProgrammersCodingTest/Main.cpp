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

// ���� : stoi�� ��ȣó���� ���� ���� �ʿ䰡 ����...
