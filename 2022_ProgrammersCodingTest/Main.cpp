#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    const int answerCount{ static_cast<int>(answers.size()) };
    const int way1[]{ 1, 2, 3, 4, 5 };
    const int way2[]{ 2, 1, 2, 3, 2, 4, 2, 5 };
    const int way3[]{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int scores[3]{};

    for (int i = 0; i < answerCount; ++i)
    {
        if (way1[i % 5] == answers[i])
        {
            scores[0] += 1;
        }

        if (way2[i % 8] == answers[i])
        {
            scores[1] += 1;
        }

        if (way3[i % 10] == answers[i])
        {
            scores[2] += 1;
        }
    }

    const int maxScore{ max(scores[0], max(scores[1], scores[2])) };

    vector<int> answer{};

    answer.reserve(3);

    for (int i = 0; i < 3; ++i)
    {
        if (scores[i] == maxScore)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
