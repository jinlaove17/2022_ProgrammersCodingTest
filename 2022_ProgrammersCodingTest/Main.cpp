#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer{};

    copy_if(arr.begin(), arr.end(), back_inserter(answer), [divisor](int n) {
        return n % divisor == 0;
        });

    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }

    return answer;
}
