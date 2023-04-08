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
            // ���� �ε��� �ٷ� �ں��� ���� ū ��(�ڿ� ū ���� ���� ��)�� ���� ������ ��ȸ�ϸ� ���� ã�´�.
            for (int j = i + 1; j <= maxIndex; ++j)
            {
                // ���� ������ ū ���� ã�Ҵٸ� �����ϰ� ����������.
                if (numbers[j] > numbers[i])
                {
                    answer[i] = numbers[j];
                    break;
                }
                else
                {
                    // ���� �����ٴ� �۰ų� ���� ��쿡��, ���� ���� ��� ���� ���Ѵ�.
                    // ����, ���� ���� �� �۴ٸ� ���̻� ��ȸ�� �ʿ� ���� �����ϰ� ����������.
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
