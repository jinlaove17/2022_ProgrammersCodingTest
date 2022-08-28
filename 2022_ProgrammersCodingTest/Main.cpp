#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;

    sort(arr.begin(), arr.end());

    const int base = *(arr.end() - 1);

    for (int i = 1; ; ++i)
    {
        bool isFound = true;

        for (int j = 0; j < arr.size() - 1; ++j)
        {
            if ((base * i) % arr[j] != 0)
            {
                isFound = false;
                break;
            }
        }

        if (isFound)
        {
            answer = base * i;
            break;
        }
    }

    return answer;
}
