int solution(int left, int right)
{
    int answer{};

    for (int i = left; i <= right; ++i)
    {
        int divisorCount{};

        for (int j = 1; j <= right; ++j)
        {
            if (i % j == 0)
            {
                divisorCount += 1;
            }
        }

        (divisorCount & 1) ? answer -= i : answer += i;
    }

    return answer;
}
