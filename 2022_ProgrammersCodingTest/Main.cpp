#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = phone_number;
    size_t length = phone_number.length();

    for (int i = 0; i < length - 4; ++i)
    {
        answer[i] = '*';
    }

    return answer;
}
