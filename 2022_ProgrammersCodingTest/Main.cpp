#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ToBinary(int n)
{
    string str;

    while (n > 0)
    {
        switch (n % 2)
        {
        case 0:
            str = "0" + str;
            break;
        case 1:
            str = "1" + str;
            break;
        }

        n /= 2;
    }

    return str;
}

vector<int> solution(string s)
{
    vector<int> answer(2, 0);

    while (s != "1")
    {
        int oneCount = count(s.begin(), s.end(), '1');

        ++answer[0];
        answer[1] += s.length() - oneCount;
        s = ToBinary(oneCount);
    }

    return answer;
}
