int solution(int n, int a, int b)
{
    int answer = 1;
    int groupA = (a - 1) / 2 + 1;
    int groupB = (b - 1) / 2 + 1;

    while (n > 0 && groupA != groupB)
    {
        groupA = (groupA - 1) / 2 + 1;
        groupB = (groupB - 1) / 2 + 1;
        n /= 2;

        ++answer;
    }

    return answer;
}
