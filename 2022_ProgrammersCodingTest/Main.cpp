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
            // �����÷ο찡 �߻��� �� �����Ƿ�, �̸� ������ ������ �����Ѵ�.
            dp[i] = dp[i - 1] % 1234567 + dp[i - 2] % 1234567;
        }

        answer = dp[n] % 1234567;
    }

    return answer;
}
