#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int count = 0;
    int start = 1;

    for (int i = 0; i < stations.size(); ++i)
    {
        count = stations[i] - w - start;
        answer += ceilf((float)count / (2 * w + 1));
        start = stations[i] + w + 1;
    }

    if (start <= n)
    {
        count = n + 1 - start;
        answer += ceilf((float)count / (2 * w + 1));
    }

    return answer;
}
