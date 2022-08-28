#include <string>
#include <bitset>

using namespace std;

int solution(int n)
{
    int answer = 0;

    bitset<32> bs(n);
    string s = bs.to_string();
    int cnt = count(s.begin(), s.end(), '1');

    for (int i = 1; ; ++i)
    {
        bs = n + i;
        s = bs.to_string();

        if (count(s.begin(), s.end(), '1') == cnt)
        {
            answer = n + i;
            break;
        }
    }

    return answer;
}

// [참고] bitset의 count() 메소드는 해당 값의 비트 1의 개수를 반환해준다.
