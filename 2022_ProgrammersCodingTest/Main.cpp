#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    sort(records.begin(), records.end(), [](const string& a, const string& b)
        {
            return a.substr(6, 4) + a.substr(0, 5) < b.substr(6, 4) + b.substr(0, 5);
        });

    map<string, int> totalParkingMins;
    int size = records.size();

    for (int i = 0; i < size; ++i)
    {
        string num = records[i].substr(6, 4);

        int inHour = atoi(records[i].substr(0, 2).c_str());
        int inMin = atoi(records[i].substr(3, 2).c_str());
        int outHour = 0;
        int outMin = 0;

        if (i < size - 1)
        {
            if (num == records[i + 1].substr(6, 4))
            {
                outHour = atoi(records[i + 1].substr(0, 2).c_str());
                outMin = atoi(records[i + 1].substr(3, 2).c_str());

                ++i;
            }
            else
            {
                outHour = 23;
                outMin = 59;
            }
        }
        else
        {
            outHour = 23;
            outMin = 59;
        }

        totalParkingMins[num] += (60 * outHour + outMin) - (60 * inHour + inMin);
    }

    for (const auto& p : totalParkingMins)
    {
        int fee = fees[1];

        if (p.second > fees[0])
        {
            int min = p.second - fees[0];

            min = static_cast<int>(ceilf((float)min / fees[2]));
            fee += fees[3] * min;
        }

        answer.push_back(fee);
    }

    return answer;
}
