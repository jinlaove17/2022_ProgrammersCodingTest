#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    // 초기 값은 무적권의 개수이다.
    int answer = k;
    int round = enemy.size();

    // 사용할 수 있는 무적권의 수가 라운드 수와 크거나 같다면, 모든 라운드에 무적권을 사용하면 되므로 라운드 수를 반환한다.
    if (k >= round)
    {
        return round;
    }

    // 최대한 많은 라운드를 막기 위해서는 무적권을 모두 사용해야 한다.
    // 우선, 1라운드부터 k라운드까지 무적권을 사용하고, 이후 더 많은 수의 적이 있는 라운드가 있다면 무적권의 사용 라운드를 교체한다.
    // 무적권을 사용한 라운드의 적의 수를 최소 힙에 저장해 놓는다.
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < k; ++i)
    {
        q.push(enemy[i]);
    }

    // k + 1라운드부터 순회를 시작한다.
    for (int i = k; i < round; ++i)
    {
        // 큐의 top은 무적권을 사용한 라운드 중 가장 적은 적의 수를 나타낸다.
        int minEnemy = q.top();

        // 현재 라운드의 적의 수와 minEnemy를 비교한다.
        if (enemy[i] > minEnemy)
        {
            // 현재 라운드의 적의 수가 더 많기 때문에, 적의수가 minEnemy인 라운드는 무적권을 사용하지 않은 라운드가 되므로 병사의 수에서 빼준다.
            int rest = n - minEnemy;

            // 만약 해당 라운드에 무적권을 사용하지 않았을 때 병사의 수가 더 많을 경우에만, 무적권 사용 라운드를 교체할 수 있다.
            if (rest >= 0)
            {
                q.pop();
                q.push(enemy[i]);
                answer = i + 1;
                n = rest;
            }
            else
            {
                break;
            }
        }
        // minEnemy보다 이번 라운드의 적의 수가 더 적다면, 무적권을 사용하지 않고 병사의 수로 막아낸다.
        else
        {
            int rest = n - enemy[i];

            if (rest >= 0)
            {
                ++answer;
                n = rest;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}
