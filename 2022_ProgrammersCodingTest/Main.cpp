#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer{};

    set<int> types{ nums.begin(), nums.end() };

    int typeCount{ static_cast<int>(types.size()) };
    int selectCount{ static_cast<int>(nums.size() / 2) };

    (typeCount >= selectCount) ? answer = selectCount : answer = typeCount;

    return answer;
}
