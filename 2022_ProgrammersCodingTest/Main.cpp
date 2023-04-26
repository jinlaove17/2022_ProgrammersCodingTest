using namespace std;

int GetGCD(int a, int b);

long long solution(int w, int h)
{
    long long answer = 1;

    // w와 h의 최대공약수를 알면, 최소 직사각형을 구할 수 있다.
    int gcd = GetGCD(w, h);
    int minWidth = w / gcd, minHeight = h / gcd;

    // 하얀 부분은 (minWidth - 1) + (minHeight - 1) + 1개씩 반복된다.
    // 이 부분에 다시 gcd를 곱해 원래 크기를 만들어준다.
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
