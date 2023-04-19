#include <string>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    int len = t.length() - p.length();
    long n = stol(p);

    for (int i = 0; i <= len; ++i)
    {
        if (stol(t.substr(i, p.length())) <= n)
        {
            ++answer;
        }
    }

    return answer;
}
