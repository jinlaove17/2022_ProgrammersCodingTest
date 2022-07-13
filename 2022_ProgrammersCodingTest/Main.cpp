#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer{};

    for (int i = 0; i < a.size(); ++i)
    {
        answer += a[i] * b[i];
    }

    return answer;
}
