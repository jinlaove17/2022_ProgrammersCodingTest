#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    for (int i = 0; i < photo.size(); ++i)
    {
        int score = 0;

        for (const auto& str : photo[i])
        {
            auto iter = find(name.begin(), name.end(), str);

            if (iter != name.end())
            {
                score += yearning[iter - name.begin()];
            }
        }

        answer.push_back(score);
    }

    return answer;
}
