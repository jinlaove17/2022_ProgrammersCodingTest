#include <string>

using namespace std;

string ToBinary(int n, int num);

string solution(int n, int t, int m, int p)
{
    string answer = "";

    string s = "01";
    int num = 2;

    while (s.length() < m * t)
    {
        s += ToBinary(n, num);
        ++num;
    }

    for (int i = p - 1; answer.size() < t; i += m)
    {
        answer.push_back(s[i]);
    }

    return answer;
}

string ToBinary(int n, int num)
{
    string s;

    while (num > 0)
    {
        char c = num % n + '0';

        if (c > '9')
        {
            c = 'A' + c - ('9' + 1);
        }

        s = string(1, c) + s;
        num /= n;
    }

    return s;
}
