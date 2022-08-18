#include <string>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    for (int i = 0; i < number.length(); ++i)
    {
        while (!answer.empty() && k > 0 && number[i] > answer.back())
        {
            answer.pop_back();
            --k;

            if (k == 0)
            {
                answer += number.substr(i, number.length() - 1);

                return answer;
            }
        }

        answer.push_back(number[i]);
    }

    return answer.substr(0, answer.length() - k);
}
