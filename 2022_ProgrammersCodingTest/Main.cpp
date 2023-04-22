#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food)
{
    string answer = "0";

    for (int i = food.size() - 1; i >= 0; --i)
    {
        int cnt = food[i] / 2;

        for (int j = 0; j < cnt; ++j)
        {
            answer = static_cast<char>(i + '0') + answer + static_cast<char>(i + '0');
        }
    }

    return answer;
}
