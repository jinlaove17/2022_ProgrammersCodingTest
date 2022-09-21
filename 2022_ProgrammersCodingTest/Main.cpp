#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer(2, 0);
    unordered_map<string, int> um;

    ++um[words[0]];

    for (int i = 1; i < words.size(); ++i)
    {
        if (um.count(words[i]) == 0 && (words[i - 1].back() == words[i].front()))
        {
            ++um[words[i]];
        }
        else
        {
            answer[0] = um.size() % n + 1;
            answer[1] = um.size() / n + 1;
            break;
        }
    }

    return answer;
}
