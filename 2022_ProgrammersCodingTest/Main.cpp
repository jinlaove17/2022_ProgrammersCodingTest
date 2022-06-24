bool solution(int x)
{
    bool answer = true;

    if (x >= 10)
    {
        int temp{ x };
        int digitSum{};

        while (temp > 0)
        {
            digitSum += temp % 10;
            temp /= 10;
        }

        if (x % digitSum != 0)
        {
            answer = false;
        }
    }

    return answer;
}