int DP[60001];

int solution(int n)
{
    int answer = 0;
    const int mod = 1'000'000'007;

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        DP[i] = DP[i - 1] % mod + DP[i - 2] % mod;
    }

    answer = DP[n] % mod;

    return answer;
}
