#include <string>

using namespace std;

string solution(int a, int b)
{
    int totalDays{ b };
    int monthOfDays[]{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < a - 1; ++i)
    {
        totalDays += monthOfDays[i];
    }

    switch (totalDays % 7)
    {
    case 0:
        return "THU";
    case 1:
        return "FRI";
    case 2:
        return "SAT";
    case 3:
        return "SUN";
    case 4:
        return "MON";
    case 5:
        return "TUE";
    case 6:
        return "WED";
    }
}
