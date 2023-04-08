#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    int maxIndex = numbers.size() - 1;

    for (int i = numbers.size() - 2; i >= 0; --i)
    {
        if (numbers[i] >= numbers[maxIndex])
        {
            maxIndex = i;
        }
        else
        {
            // 현재 인덱스 바로 뒤부터 가장 큰 수(뒤에 큰 수가 없는 수)가 나올 때까지 순회하며 값을 찾는다.
            for (int j = i + 1; j <= maxIndex; ++j)
            {
                // 현재 값보다 큰 값을 찾았다면 저장하고 빠져나간다.
                if (numbers[j] > numbers[i])
                {
                    answer[i] = numbers[j];
                    break;
                }
                else
                {
                    // 현재 값보다는 작거나 같을 경우에는, 현재 값과 결과 값을 비교한다.
                    // 만약, 현재 값이 더 작다면 더이상 순회할 필요 없이 저장하고 빠져나간다.
                    if (numbers[i] < answer[j])
                    {
                        answer[i] = answer[j];
                        break;
                    }
                }
            }
        }
    }

    return answer;
}
