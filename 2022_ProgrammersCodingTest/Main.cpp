using namespace std;

int GetGCD(int a, int b);

long long solution(int w, int h)
{
    long long answer = 1;

    // w�� h�� �ִ������� �˸�, �ּ� ���簢���� ���� �� �ִ�.
    int gcd = GetGCD(w, h);
    int minWidth = w / gcd, minHeight = h / gcd;

    // �Ͼ� �κ��� (minWidth - 1) + (minHeight - 1) + 1���� �ݺ��ȴ�.
    // �� �κп� �ٽ� gcd�� ���� ���� ũ�⸦ ������ش�.
    answer = static_cast<long long>(w) * static_cast<long long>(h) - (minWidth + minHeight - 1) * gcd;

    return answer;
}

int GetGCD(int a, int b)
{
    int c = 0;

    while (b > 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
