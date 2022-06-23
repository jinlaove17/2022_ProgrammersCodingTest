#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    set<int> result{};
    int numberCount{ static_cast<int>(numbers.size()) };

    for (int i = 0; i < numberCount - 1; ++i)
    {
        for (int j = i + 1; j < numberCount; ++j)
        {
            result.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> answer{ result.begin(), result.end() };

    return answer;
}
