#include <vector>

using namespace std;

int GetGCD(int a, int b);

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;

    // �� �迭�� ũ��� �׻� �����Ƿ� ���� ũ�Ⱑ 1�̶��, �� �� �� ū ���� a���� �ȴ�.
    // �̶�, �� ���� ���ٸ�, ������ �����ϴ� a�� �������� �ʴ´�.
    if (arrayA.size() == 1)
    {
        if (arrayA[0] == arrayB[0])
        {
            return 0;
        }
        else
        {
            return max(arrayA[0], arrayB[0]);
        }
    }

    // arrayA�� �ִ� ������� ���Ѵ�.
    int gcdA = GetGCD(arrayA[0], arrayA[1]);

    for (int i = 2; i < arrayA.size(); ++i)
    {
        gcdA = GetGCD(gcdA, arrayA[i]);
    }

    // arrayB�� �ִ� ������� ���Ѵ�.
    int gcdB = GetGCD(arrayB[0], arrayB[1]);

    for (int i = 2; i < arrayB.size(); ++i)
    {
        gcdB = GetGCD(gcdB, arrayB[i]);
    }

    // gcdA�� gcdB�� ��� 1�̰ų� ���� ��쿡�� ������ �����ϴ� a�� �������� �ʴ´�.
    if (((gcdA == 1) && (gcdB == 1)) || (gcdA == gcdB))
    {
        return 0;
    }
    // �ϳ��� 1�� �ƴ� ��쿡�� ū ������ ������ �迭�� ������ a���� �� �� �ִ��� �˻��Ѵ�.
    else
    {
        if (gcdA > gcdB)
        {
            for (int i = 0; i < arrayB.size(); ++i)
            {
                if (arrayB[i] % gcdA == 0)
                {
                    return 0;
                }
            }

            answer = gcdA;
        }
        else
        {
            for (int i = 0; i < arrayA.size(); ++i)
            {
                if (arrayA[i] % gcdB == 0)
                {
                    return 0;
                }
            }

            answer = gcdB;
        }
    }

    return answer;
}

int GetGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GetGCD(b, a % b);
}
