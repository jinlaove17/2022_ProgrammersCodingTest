#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    unordered_set<int> s;
    int size = elements.size();

    // 길이
    for (int i = 1; i <= size; ++i)
    {
        // 현재 인덱스
        for (int j = 0; j < size; ++j)
        {
            int sum = 0;

            // 현재 인덱스부터 길이만큼의 합
            for (int k = 0; k < i; ++k)
            {
                sum += elements[(j + k) % size];
            }

            s.insert(sum);
        }
    }

    answer = s.size();

    return answer;
}
