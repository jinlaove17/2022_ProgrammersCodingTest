#include <string>
#include <vector>

using namespace std;

int GetDistance(int current, int target);

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int leftNumber = 10, rightNumber = 12;

    for (int i = 0; i < numbers.size(); ++i)
    {
        switch (numbers[i])
        {
        case 1:
        case 4:
        case 7:
            leftNumber = numbers[i];
            answer += "L";
            break;
        case 3:
        case 6:
        case 9:
            rightNumber = numbers[i];
            answer += "R";
            break;
        case 0:
            numbers[i] = 11;
        case 2:
        case 5:
        case 8:
        {
            int leftDistance = GetDistance(leftNumber, numbers[i]);
            int rightDistance = GetDistance(rightNumber, numbers[i]);

            if (leftDistance < rightDistance)
            {
                leftNumber = numbers[i];
                answer += "L";
            }
            else if (leftDistance == rightDistance)
            {
                if (hand == "left")
                {
                    leftNumber = numbers[i];
                    answer += "L";
                }
                else if (hand == "right")
                {
                    rightNumber = numbers[i];
                    answer += "R";
                }
            }
            else
            {
                rightNumber = numbers[i];
                answer += "R";
            }
        }
            break;
        }
    }

    return answer;
}

int GetDistance(int current, int target)
{
    int width = abs((target - 1) % 3 - (current - 1) % 3);
    int height = abs((target - 1) / 3 - (current - 1) / 3);

    return width + height;
}
