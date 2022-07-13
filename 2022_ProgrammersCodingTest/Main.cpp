//#include <cmath>

long long solution(int price, int money, int count)
{
    long long answer{};
    long long totalPrice{};

    for (int i = 1; i <= count; ++i)
    {
        totalPrice += price * i;
    }

    answer = money - totalPrice;

    return (answer > 0) ? 0 : -answer; // abs(answer); 이건 왜 안되는지..?
}
