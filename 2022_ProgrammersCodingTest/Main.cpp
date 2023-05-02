#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "Yes";

    reverse(cards1.begin(), cards1.end());
    reverse(cards2.begin(), cards2.end());

    for (const string& word : goal)
    {
        if ((!cards1.empty()) && (cards1.back() == word))
        {
            cards1.pop_back();
        }
        else if ((!cards2.empty()) && (cards2.back() == word))
        {
            cards2.pop_back();
        }
        else
        {
            answer = "No";
            break;
        }
    }

    return answer;
}
