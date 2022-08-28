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

// [����] bitset�� count() �޼ҵ�� �ش� ���� ��Ʈ 1�� ������ ��ȯ���ش�.
