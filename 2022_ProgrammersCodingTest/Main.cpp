#include <cmath>

void NQueen(const int n, const int i, int* column, int& cases);
bool CheckAttack(const int i, int* column);

int solution(int n)
{
    int answer{};
    int* column{ new int[n] {} };

    NQueen(n, 0, column, answer);

    delete[] column;

    return answer;
}

void NQueen(const int n, const int i, int* column, int& cases)
{
    if (i == n)
    {
        cases += 1;
    }
    else
    {
        for (int j = 0; j < n; ++j)
        {
            column[i] = j;

            if (!CheckAttack(i, column))
            {
                NQueen(n, i + 1, column, cases);
            }
        }
    }
}

bool CheckAttack(const int i, int* column)
{
    for (int j = 0; j < i; ++j)
    {
        if (column[i] == column[j]) // 가로 공격 체크
        {
            return true;
        }
        else if (i - j == abs(column[i] - column[j])) // 대각선 공격 체크
        {
            return true;
        }
    }

    return false;
}
