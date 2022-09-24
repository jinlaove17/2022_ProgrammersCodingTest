#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    answer.reserve(right - left + 1);

    // left와 right가 속한 그룹의 번호를 구한다.
    int leftGroup = left / n + 1;
    int rightGroup = right / n + 1;

    // left 그룹부터 right 그룹까지 순회하며, answer의 값을 채운다.
    for (int i = leftGroup; i <= rightGroup; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            answer.push_back(i);
        }

        for (int k = 0, num = i + 1; k < n - i; ++k, ++num)
        {
            answer.push_back(num);
        }
    }

    // 각 그룹에서 left, right만큼 이동하여 시작과 끝 위치를 구하고, answer를 재할당한다.
    answer.assign(answer.begin() + left % n, answer.end() - (n - right % n) + 1);

    return answer;
}
