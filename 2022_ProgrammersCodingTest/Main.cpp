#include <vector>
#include <map>

using namespace std;

int GetGCD(int a, int b);
int GetLCM(int a, int b);

long long solution(vector<int> weights)
{
    long long answer = 0;

    // 각 몸무게별로 사람이 몇 명씩 있는지 구한다.
    map<int, int> m;

    for (int weight : weights)
    {
        ++m[weight];
    }

    for (auto iter1 = m.begin(); iter1 != m.end(); )
    {
        // 동일한 몸무게를 가진 사람이 여러명이라면, 동일 몸무게 간의 쌍의 개수를 구한다.  
        for (int i = 0; i < iter1->second - 1; ++i)
        {
            for (int j = i + 1; j < iter1->second; ++j)
            {
                ++answer;
            }
        }

        for (auto iter2 = m.begin(); iter2 != m.end(); ++iter2)
        {
            // 동일한 몸무게에 대한 쌍의 개수는 위에서 구했으므로, 몸무게가 다를 경우에만 쌍의 개수를 구한다.
            if (iter1->first != iter2->first)
            {
                int lcm = GetLCM(iter1->first, iter2->first);

                // map 컨테이너를 사용했기 때문에 항상 iter2->first가 iter1->first보다 크다는 것을 보장한다.
                // 만약, 두 수의 최소 공배수가 iter2->first가 나왔다면, 1m 좌석은 없으므로 2m 좌석에 앉아야 한다.
                if (lcm == iter2->first)
                {
                    lcm *= 2;
                }

                // 최소 공배수를 두 수 중 작은 값으로 나누었을 때의 몫은 4(m)이하여야 한다.
                if (lcm / iter1->first <= 4)
                {
                    answer += iter1->second * iter2->second;
                }
            }
        }

        // 몸무게가 iter1->first인 사람들을 포함하는 쌍은 구했으므로, 중복되지 않도록 컨테이너에서 삭제시킨다.
        // 사실상 밖의 for문은 원소를 삭제하며 순회하는 것과 같다.
        iter1 = m.erase(iter1);
    }

    return answer;
}

int GetGCD(int a, int b)
{
    int temp = 0;

    while (b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int GetLCM(int a, int b)
{
    return a * b / GetGCD(a, b);
}
