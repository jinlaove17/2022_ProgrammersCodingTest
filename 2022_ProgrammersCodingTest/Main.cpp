#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end());

    for (int n = citations.size(); n >= 0; --n)
    {
        int pivot = lower_bound(citations.begin(), citations.end(), n) - citations.begin();
        int quotedCount = (citations.size() - 1) - pivot + 1;
        int restCount = pivot - 1;

        if (quotedCount >= n && restCount <= n)
        {
            answer = n;
            break;
        }
    }

    return answer;
}
