int solution(int num)
{
    int answer{};
    
    if (num > 1)
    {
        // 문제 오류 : int num은 홀수 조건을 수행하다가 오버플로우가 발생함.
        long num2 = num;

        while (num2 != 1 && answer < 500)
        {
            if (num2 % 2 == 0)
            {
                num2 /= 2;
            }
            else
            {
                num2 = 3 * num2 + 1;
            }

            answer += 1;
        }

        if (answer >= 500)
        {
            answer = -1;
        }
    }

    return answer;
}
