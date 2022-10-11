#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(vector<bool>& isVisited, unordered_set<int>& us, const string& numbers, string& current);
bool CheckPrimeNumber(int num);

int solution(string numbers)
{
    int answer = 0;

    vector<bool> isVisited(numbers.size());
    unordered_set<int> us;
    string s;

    DFS(isVisited, us, numbers, s);

    answer = us.size();

    return answer;
}

void DFS(vector<bool>& isVisited, unordered_set<int>& us, const string& numbers, string& current)
{
    if (!current.empty())
    {
        int num = stoi(current);

        if (CheckPrimeNumber(num))
        {
            us.insert(num);
        }
    }

    int size = numbers.size();

    for (int i = 0; i < size; ++i)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;

            string s = current + string(1, numbers[i]);

            DFS(isVisited, us, numbers, s);

            isVisited[i] = false;
        }
    }
}

bool CheckPrimeNumber(int num)
{
    bool isPrimeNumber = true;

    if (num < 2 || (num > 2 && num % 2 == 0))
    {
        isPrimeNumber = false;
    }
    else
    {
        int sqrtNum = sqrtf(num);

        for (int i = 2; i <= sqrtNum; ++i)
        {
            if (num % i == 0)
            {
                isPrimeNumber = false;
                break;
            }
        }
    }

    return isPrimeNumber;
}
