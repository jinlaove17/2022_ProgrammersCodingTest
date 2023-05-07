#include <vector>

using namespace std;

int GetGCD(int a, int b);

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;

    // 두 배열의 크기는 항상 같으므로 만약 크기가 1이라면, 두 수 중 큰 값이 a값이 된다.
    // 이때, 두 값이 같다면, 조건을 만족하는 a는 존재하지 않는다.
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

    // arrayA의 최대 공약수를 구한다.
    int gcdA = GetGCD(arrayA[0], arrayA[1]);

    for (int i = 2; i < arrayA.size(); ++i)
    {
        gcdA = GetGCD(gcdA, arrayA[i]);
    }

    // arrayB의 최대 공약수를 구한다.
    int gcdB = GetGCD(arrayB[0], arrayB[1]);

    for (int i = 2; i < arrayB.size(); ++i)
    {
        gcdB = GetGCD(gcdB, arrayB[i]);
    }

    // gcdA와 gcdB가 모두 1이거나 같은 경우에는 조건을 만족하는 a가 존재하지 않는다.
    if (((gcdA == 1) && (gcdB == 1)) || (gcdA == gcdB))
    {
        return 0;
    }
    // 하나라도 1이 아닌 경우에는 큰 값으로 나머지 배열을 나누어 a값이 될 수 있는지 검사한다.
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
