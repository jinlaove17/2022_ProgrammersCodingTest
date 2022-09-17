#include <string>

using namespace std;

string solution(string s)
{
    string answer = "";

    int min = INT_MAX;
    int max = INT_MIN;

    char* p = strtok(const_cast<char*>(s.c_str()), " ");

    while (p != NULL)
    {
        int val = atoi(p);

        if (val < min)
        {
            min = val;
        }

        if (val > max)
        {
            max = val;
        }

        p = strtok(NULL, " ");
    }

    answer = to_string(min) + " " + to_string(max);

    return answer;
}
