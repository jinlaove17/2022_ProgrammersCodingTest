#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    string strNum{ to_string(n) };

    sort(strNum.begin(), strNum.end(), greater<char>());

    long long answer{ stoll(strNum) };

    return answer;
}
