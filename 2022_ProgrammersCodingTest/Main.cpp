long long solution(int n)
{
    long long answer = 0;

    if (n <= 2)
    {
        answer = n;
    }
    else
    {
        int dp[2001] = { 0, 1, 2, };

        for (int i = 3; i <= n; ++i)
        {
            // 오버플로우가 발생할 수 있으므로, 미리 나머지 연산을 수행한다.
            dp[i] = dp[i - 1] % 1234567 + dp[i - 2] % 1234567;
        }

        answer = dp[n] % 1234567;
    }

    return answer;
}
