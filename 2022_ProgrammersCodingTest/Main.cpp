#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(),
        [](int a, int b)
        {
            string s1 = to_string(a) + to_string(b);
            string s2 = to_string(b) + to_string(a);

            return s1 > s2;
        });

    if (numbers[0] == 0)
    {
        answer = "0";

        return answer;
    }

    for (int number : numbers)
    {
        answer += to_string(number);
    }

    return answer;
}
