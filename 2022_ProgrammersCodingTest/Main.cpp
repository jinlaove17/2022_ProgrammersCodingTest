#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul)
{
    int index{ static_cast<int>(find(seoul.begin(), seoul.end(), "Kim") - seoul.begin()) };
    string answer{ "김서방은 " + to_string(index) + "에 있다" };

    return answer;
}
