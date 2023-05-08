#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0;

    // minerals�� 5���� ������, ���� �ε����� ������ �ջ� ��ġ�� ���Ѵ�.
    // diamond: +100, iron: +10, stone: +1
    // <index, totalValue>
    vector<pair<int, int>> values;
    int totalPick = picks[0] + picks[1] + picks[2];

    for (int i = 0; i < minerals.size(); i += 5)
    {
        // ����� �� ������ �Ѿ�� �ʵ��� ������ ������ �Ѵ�.
        if (values.size() == totalPick)
        {
            break;
        }

        int value = 0;

        for (int j = i; j < i + 5; ++j)
        {
            // �ε����� ��� ���, ���� �ݺ����� ����������.
            if (j >= minerals.size())
            {
                break;
            }

            if (minerals[j] == "diamond")
            {
                value += 100;
            }
            else if (minerals[j] == "iron")
            {
                value += 10;
            }
            else
            {
                value += 1;
            }
        }

        // ���� �ε�����, �ջ� ��ġ�� ���Ϳ� �߰��Ѵ�.
        values.push_back({ i, value });
    }

    // �ջ� ��ġ�� �������� �������� �����Ѵ�.
    sort(values.begin(), values.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    // �� ������ �Ƿε��� ����Ѵ�.
    for (int i = 0; i < values.size(); ++i)
    {
        int pickIdx = -1;

        // ��̴� �Ƿε��� ���� �ö󰡴� diamond -> iron -> stone ������ ����Ѵ�.
        if (picks[0] > 0)
        {
            pickIdx = 0;
        }
        else if (picks[1] > 0)
        {
            pickIdx = 1;
        }
        else
        {
            pickIdx = 2;
        }

        // ����� ����� ������ ���ҽ�Ų��.
        --picks[pickIdx];

        // �����ص� ���� �ε������� �����Ͽ� 5���� ĳ�µ� �Ҹ�Ǵ� �Ƿε��� ����Ѵ�.
        for (int j = values[i].first; j < values[i].first + 5; ++j)
        {
            if (j >= minerals.size())
            {
                break;
            }

            if (minerals[j] == "diamond")
            {
                switch (pickIdx)
                {
                case 0:
                    answer += 1;
                    break;
                case 1:
                    answer += 5;
                    break;
                case 2:
                    answer += 25;
                    break;
                }
            }
            else if (minerals[j] == "iron")
            {
                switch (pickIdx)
                {
                case 0:
                case 1:
                    answer += 1;
                    break;
                case 2:
                    answer += 5;
                    break;
                }
            }
            else
            {
                answer += 1;
            }
        }
    }

    return answer;
}
