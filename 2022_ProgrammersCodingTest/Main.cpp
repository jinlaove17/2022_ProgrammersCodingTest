int solution(int n)
{
    int answer = 0;

    while (n > 0)
    {
        if (n & 1)
        {
            --n;
            ++answer;
        }
        else
        {
            n /= 2;
        }
    }

    return answer;
}
