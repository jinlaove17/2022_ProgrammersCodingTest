#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;

    string numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < 10; ++i)
    {
        int pos = 0;

        while ((pos = s.find(numbers[i], pos)) != string::npos)
        {
            s.replace(pos, numbers[i].length(), to_string(i));
        }
    }

    answer = stoi(s);

    return answer;
}
