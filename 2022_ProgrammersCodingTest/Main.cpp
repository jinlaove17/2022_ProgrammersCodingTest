#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (const string& phoneNumber : phone_book)
    {
        auto endRange = lower_bound(phone_book.begin(), phone_book.end(), phoneNumber);
        auto startRange = lower_bound(phone_book.begin(), endRange, string{ phoneNumber[0] });
        auto stringRange = ++phoneNumber.begin();

        while (stringRange != phoneNumber.end())
        {
            if (binary_search(startRange, endRange, string{ phoneNumber.begin(), stringRange }))
            {
                answer = false;

                return answer;
            }

            ++stringRange;
        }
    }

    return answer;
}
