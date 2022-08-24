#include <string>
#include <array>

using namespace std;

array<array<bool, 2500>, 2500> DP;

int solution(string s)
{
    // 알파벳 하나는 팰린드롬이므로, 최소 길이는 1이다.
    int answer = 1;

    // 길이가 1 또는 2인 문자열은 팰린드롬이므로, DP의 값을 갱신한다.
    for (int i = 0; i < s.length(); ++i)
    {
        DP[i][i] = true;

        if (i < s.length() - 1)
        {
            if (s[i] == s[i + 1])
            {
                DP[i][i + 1] = true;
                answer = 2;
            }
        }
    }

    // 길이가 3이상인 문자열이 팰린드롬인지 검사하고, DP의 값을 갱신한다.
    // 즉, 양 끝(start, end)의 값이 같아야 하고, 그 사이(start + 1, end - 1)가 팰린드롬이면 갱신한다.
    for (int len = 3; len <= s.length(); ++len)
    {
        for (int start = 0; start <= s.length() - len; ++start)
        {
            int end = start + len - 1;

            if (s[start] == s[end] && DP[start + 1][end - 1])
            {
                DP[start][end] = true;
                answer = len;
            }
        }
    }

    return answer;
}

// 참고: https://yabmoons.tistory.com/545?category=946153
