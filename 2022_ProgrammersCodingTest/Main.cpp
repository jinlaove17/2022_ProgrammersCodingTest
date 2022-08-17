#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> um;

    for (const auto& cloth : clothes)
    {
        um[cloth[1]] += 1;
    }

    for (const auto& cloth : um)
    {
        // + 1 : 입지 않는 경우의 수
        answer *= (cloth.second + 1);
    }

    // - 1 : 모든 종류의 옷을 입지 않는 경우의 수
    answer -= 1;

    return answer;
}
