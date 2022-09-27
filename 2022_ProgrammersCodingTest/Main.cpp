#include <string>
#include <vector>

using namespace std;

string ToBinary(int n, int k);
bool IsPrimeNumber(long long n);

int solution(int n, int k)
{
    int answer = 0;

    string s = ToBinary(n, k);

    vector<long long> v;
    string str;

    for (char c : s)
    {
        switch (c)
        {
        case '0':
            if (!str.empty())
            {
                v.push_back(atoll(str.c_str()));
            }

            str.clear();
            break;
        default:
            str.push_back(c);
            break;
        }
    }

    if (!str.empty())
    {
        v.push_back(atoll(str.c_str()));
    }

    for (long long num : v)
    {
        if (IsPrimeNumber(num))
        {
            ++answer;
        }
    }

    return answer;
}

string ToBinary(int n, int k)
{
    string s;

    while (n > 0)
    {
        s = string(1, n % k + '0') + s;
        n /= k;
    }

    return s;
}

bool IsPrimeNumber(long long n)
{
    bool isPrimeNumber = true;

    if (n <= 1)
    {
        isPrimeNumber = false;
    }
    else
    {
        long long sqrtN = sqrtf(n);

        for (long long i = 2; i <= sqrtN; ++i)
        {
            if (n % i == 0)
            {
                isPrimeNumber = false;
                break;
            }
        }
    }

    return isPrimeNumber;
}
