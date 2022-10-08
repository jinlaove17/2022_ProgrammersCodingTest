#include <vector>
#include <bitset>

using namespace std;

long long f(long long n);

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long number : numbers)
    {
        answer.push_back(f(number));
    }

    return answer;
}

long long f(long long n)
{
    bitset<64> bs = n;

    if (bs[0] == 0)
    {
        bs[0] = 1;
    }
    else
    {
        // bitset의 인덱스는 오른쪽부터 시작한다.
        int lastZeroLoc = bs.size() - bs.to_string().rfind('0') - 1;

        bs[lastZeroLoc] = 1;
        bs[lastZeroLoc - 1] = 0;
    }

    return bs.to_ulong();
}
