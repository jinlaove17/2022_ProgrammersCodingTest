#include <vector>

using namespace std;

void GetTargetNumber(vector<int>& numbers, int index, const int target, int current, int& answer);

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    GetTargetNumber(numbers, 0, target, 0, answer);

    return answer;
}

void GetTargetNumber(vector<int>& numbers, int index, const int target, int current, int& answer)
{
    if (index == numbers.size())
    {
        if (current == target)
        {
            answer += 1;
        }
    }
    else
    {
        GetTargetNumber(numbers, index + 1, target, current + numbers[index], answer);
        GetTargetNumber(numbers, index + 1, target, current - numbers[index], answer);
    }
}
