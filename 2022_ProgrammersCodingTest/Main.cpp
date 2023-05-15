#include <vector>
#include <map>

using namespace std;

int GetGCD(int a, int b);
int GetLCM(int a, int b);

long long solution(vector<int> weights)
{
    long long answer = 0;

    // �� �����Ժ��� ����� �� �� �ִ��� ���Ѵ�.
    map<int, int> m;

    for (int weight : weights)
    {
        ++m[weight];
    }

    for (auto iter1 = m.begin(); iter1 != m.end(); )
    {
        // ������ �����Ը� ���� ����� �������̶��, ���� ������ ���� ���� ������ ���Ѵ�.  
        for (int i = 0; i < iter1->second - 1; ++i)
        {
            for (int j = i + 1; j < iter1->second; ++j)
            {
                ++answer;
            }
        }

        for (auto iter2 = m.begin(); iter2 != m.end(); ++iter2)
        {
            // ������ �����Կ� ���� ���� ������ ������ �������Ƿ�, �����԰� �ٸ� ��쿡�� ���� ������ ���Ѵ�.
            if (iter1->first != iter2->first)
            {
                int lcm = GetLCM(iter1->first, iter2->first);

                // map �����̳ʸ� ����߱� ������ �׻� iter2->first�� iter1->first���� ũ�ٴ� ���� �����Ѵ�.
                // ����, �� ���� �ּ� ������� iter2->first�� ���Դٸ�, 1m �¼��� �����Ƿ� 2m �¼��� �ɾƾ� �Ѵ�.
                if (lcm == iter2->first)
                {
                    lcm *= 2;
                }

                // �ּ� ������� �� �� �� ���� ������ �������� ���� ���� 4(m)���Ͽ��� �Ѵ�.
                if (lcm / iter1->first <= 4)
                {
                    answer += iter1->second * iter2->second;
                }
            }
        }

        // �����԰� iter1->first�� ������� �����ϴ� ���� �������Ƿ�, �ߺ����� �ʵ��� �����̳ʿ��� ������Ų��.
        // ��ǻ� ���� for���� ���Ҹ� �����ϸ� ��ȸ�ϴ� �Ͱ� ����.
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
