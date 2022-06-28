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

// �������� Ǯ ���� min_element��� �Լ��� �����ϰ� ����غ���.
