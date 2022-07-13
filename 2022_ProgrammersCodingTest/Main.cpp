#include <vector>
#include <set>

using namespace std;

int solution(vector<int> numbers)
{
    int answer{};

    set<int> uniqueNumbers{ numbers.begin(), numbers.end() };

    for (int i = 0; i <= 9; ++i)
    {
        if (!uniqueNumbers.count(i))
        {
            answer += i;
        }
    }

    return answer;
}
