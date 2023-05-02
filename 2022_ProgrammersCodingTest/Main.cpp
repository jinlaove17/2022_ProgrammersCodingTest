#include <string>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    string results[3] = {};

    // 1. 다트의 총 결과를 각각의 결과로 분리시킨다.
    for (int i = 0, j = 0; i < dartResult.length(); ++i)
    {
        switch (dartResult[i])
        {
        case 'S':
        case 'D':
        case 'T':
            results[j].push_back(dartResult[i]);

            if (i + 1 < dartResult.length())
            {
                switch (dartResult[i + 1])
                {
                case '*':
                case '#':
                    results[j].push_back(dartResult[++i]);
                    break;
                }

                ++j;
            }
            break;
        default:
            results[j].push_back(dartResult[i]);
            break;
        }
    }

    int scores[3] = {};

    // 2. 분리시킨 문자열을 기반으로 점수를 계산한다.
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < results[i].length(); ++j)
        {
            if (results[i][j] == 'S')
            {
                scores[i] = stoi(results[i].substr(0, j));

                if (j + 1 < results[i].length())
                {
                    switch (results[i][j + 1])
                    {
                    case '*':
                        scores[i] *= 2;

                        if (i >= 1)
                        {
                            scores[i - 1] *= 2;
                        }
                        break;
                    case '#':
                        scores[i] = -scores[i];
                        break;
                    }
                }
                break;
            }
            else if (results[i][j] == 'D')
            {
                scores[i] = stoi(results[i].substr(0, j));
                scores[i] = scores[i] * scores[i];

                if (j + 1 < results[i].length())
                {
                    switch (results[i][j + 1])
                    {
                    case '*':
                        scores[i] *= 2;

                        if (i >= 1)
                        {
                            scores[i - 1] *= 2;
                        }
                        break;
                    case '#':
                        scores[i] = -scores[i];
                        break;
                    }
                }
                break;
            }
            else if (results[i][j] == 'T')
            {
                scores[i] = stoi(results[i].substr(0, j));
                scores[i] = scores[i] * scores[i] * scores[i];

                if (j + 1 < results[i].length())
                {
                    switch (results[i][j + 1])
                    {
                    case '*':
                        scores[i] *= 2;

                        if (i >= 1)
                        {
                            scores[i - 1] *= 2;
                        }
                        break;
                    case '#':
                        scores[i] = -scores[i];
                        break;
                    }
                }
                break;
            }
        }
    }

    // 3. 각각의 점수를 합산하여 총 점수를 구한다.
    for (int i = 0; i < 3; ++i)
    {
        answer += scores[i];
    }

    return answer;
}
