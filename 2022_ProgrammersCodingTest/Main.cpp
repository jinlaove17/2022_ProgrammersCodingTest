#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    // ũ�⿡ ���� ���� ������ ���Ѵ�.
    unordered_map<int, int> counts;

    for (int n : tangerine)
    {
        ++counts[n];
    }

    // ���� ����
    vector<int> v;

    v.reserve(counts.size());

    for (auto iter = counts.begin(); iter != counts.end(); ++iter)
    {
        v.push_back(iter->second);
    }

    // ���� ������ ���� ������������ �����Ѵ�.
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    // ������������ ���ĵ� ���͸� ��ȸ�ϸ�, ���� ������ 0�� ���ϰ� �� ������ ���� ��´�.
    for (int n : v)
    {
        k -= n;
        ++answer;

        if (k <= 0)
        {
            break;
        }
    }

    return answer;
}
