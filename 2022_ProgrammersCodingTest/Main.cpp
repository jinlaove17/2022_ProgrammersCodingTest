#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr)
{
    if (arr.size() == 1)
    {
        arr[0] = -1;
    }
    else
    {
        int arrSize{ static_cast<int>(arr.size()) };
        int minValue{ INT_MAX };
        int minIndex{};

        for (int i = 0; i < arrSize; ++i)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
                minIndex = i;
            }
        }

        arr.erase(next(arr.begin(), minIndex));
    }

    return arr;
}

// 다음번에 풀 때는 min_element라는 함수를 공부하고 사용해보자.
