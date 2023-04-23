#include <string>
#include <vector>

using namespace std;

char prioritys[6][3] =
{
    { '+', '-', '*' },
    { '+', '*', '-' },
    { '-', '*', '+' },
    { '-', '+', '*' },
    { '*', '+', '-' },
    { '*', '-', '+' }
};

long long solution(string expression)
{
    long long answer = 0;
    vector<long long> operands;
    vector<char> operators;
    string str;

    for (char c : expression)
    {
        if (('0' <= c) && (c <= '9'))
        {
            str.push_back(c);
        }
        else
        {
            operators.push_back(c);
            operands.push_back(stoll(str));
            str.clear();
        }
    }

    operands.push_back(stoll(str));

    for (int i = 0; i < 6; ++i)
    {
        vector<long long> tempOperands(operands);
        vector<char> tempOperators(operators);

        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < tempOperators.size(); )
            {
                if (tempOperators[k] == prioritys[i][j])
                {
                    switch (tempOperators[k])
                    {
                    case '+':
                        tempOperands[k] = tempOperands[k] + tempOperands[k + 1];
                        break;
                    case '-':
                        tempOperands[k] = tempOperands[k] - tempOperands[k + 1];
                        break;
                    case '*':
                        tempOperands[k] = tempOperands[k] * tempOperands[k + 1];
                        break;
                    }

                    tempOperands.erase(tempOperands.begin() + k + 1);
                    tempOperators.erase(tempOperators.begin() + k);
                }
                else
                {
                    ++k;
                }
            }
        }

        answer = max(answer, abs(tempOperands[0]));
    }

    return answer;
}
