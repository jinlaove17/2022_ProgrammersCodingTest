#include <string>

using namespace std;

string solution(int n)
{
    string answer = "";

    int share = n;
    int reminder = 0;

    while (share > 0)
    {
        reminder = share % 3;
        share /= 3;

        switch (reminder)
        {
        case 0:
            answer = "4" + answer;
            --share;
            break;
        case 1:
            answer = "1" + answer;
            break;
        case 2:
            answer = "2" + answer;
            break;
        }
    }

    return answer;
}
