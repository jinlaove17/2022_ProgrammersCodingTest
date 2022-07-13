#include <string>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer{};
    string number{};

    while (n > 0)
    {
        number.push_back((n % 3) + '0');
        n /= 3;
    }

    int length{ static_cast<int>(number.length()) };

    for (int i = 0; i < length; ++i)
    {
        answer += pow(3, length - 1 - i) * (number[i] - '0');
    }

    return answer;
}
