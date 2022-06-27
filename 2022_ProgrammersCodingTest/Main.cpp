#include <vector>

using namespace std;

int CalculateGCD(int greater, int less)
{
    int remainder{};

    while (less != 0)
    {
        remainder = greater % less;
        greater = less;
        less = remainder;
    }

    return greater;
}

int CalculateLCM(int greater, int less)
{
    return greater * less / CalculateGCD(greater, less);
}

vector<int> solution(int n, int m)
{
    vector<int> answer{};

    if (n > m)
    {
        answer.push_back(CalculateGCD(n, m));
        answer.push_back(CalculateLCM(n, m));
    }
    else
    {
        answer.push_back(CalculateGCD(m, n));
        answer.push_back(CalculateLCM(m, n));
    }
   
    return answer;
}
