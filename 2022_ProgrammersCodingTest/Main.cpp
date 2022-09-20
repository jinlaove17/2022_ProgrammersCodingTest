long long f[100'001];

int solution(int n)
{
    int answer = 0;

    f[1] = f[2] = 1;

    for (int i = 3; i <= 100'000; ++i)
    {
        // 오버플로우 문제를 해결해야함!
        f[i] = f[i - 1] % 1234567 + f[i - 2] % 1234567;
    }

    answer = f[n] % 1234567;

    return answer;
}
