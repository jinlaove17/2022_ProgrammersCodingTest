#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    int answer{};
    int numberCount{ static_cast<int>(nums.size()) };

    for (int i = 0; i < numberCount - 2; ++i)
    {
        for (int j = i + 1; j < numberCount - 1; ++j)
        {
            for (int k = i + 2; k < numberCount; ++k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum & 1)
                {
                    bool isPrimeNum{ true };

                    for (int l = 2; l < sum; ++l)
                    {
                        if (sum % l == 0)
                        {
                            isPrimeNum = false;
                            break;
                        }
                    }

                    if (isPrimeNum)
                    {
                        answer += 1;
                    }
                }
            }
        }

    }

    return answer;
}
