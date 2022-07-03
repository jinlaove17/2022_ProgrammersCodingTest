long long solution(int a, int b)
{
    long long answer{};

    if (a > b)
    {
        for (int i = b; i <= a; ++i)
        {
            answer += i;
        }
    }
    else if (a == b)
    {
        answer = a;
    }
    else
    {
        for (int i = a; i <= b; ++i)
        {
            answer += i;
        }
    }




    return answer;
}
