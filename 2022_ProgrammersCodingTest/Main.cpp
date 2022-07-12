int solution(int n)
{
    int answer{};

    if (n & 1)
    {
        answer = 2;
    }
    else
    {
        for (int i = 3; i < n; i += 2)
        {
            if (n % i == 1)
            {
                answer = i;
                break;
            }
        }
    }

    return answer;
}
