#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    // 크기에 따른 귤의 개수를 구한다.
    unordered_map<int, int> counts;

    for (int n : tangerine)
    {
        ++counts[n];
    }

    // 귤의 개수
    vector<int> v;

    v.reserve(counts.size());

    for (auto iter = counts.begin(); iter != counts.end(); ++iter)
    {
        v.push_back(iter->second);
    }

    // 귤의 개수에 따라 내림차순으로 정렬한다.
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    // 내림차순으로 정렬된 벡터를 순회하며, 귤의 개수가 0개 이하가 될 때까지 귤을 담는다.
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
