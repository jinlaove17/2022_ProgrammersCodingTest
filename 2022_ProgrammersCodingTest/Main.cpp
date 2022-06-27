int solution(int num)
{
    int answer{};
    
    if (num > 1)
    {
        // ���� ���� : int num�� Ȧ�� ������ �����ϴٰ� �����÷ο찡 �߻���.
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
