#include <string>
#include <vector>

using namespace std;

string ToBinary(int n);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; ++i)
    {
        string map;
        string s1 = ToBinary(arr1[i]);
        string s2 = ToBinary(arr2[i]);

        while (!s1.empty() && !s2.empty())
        {
            if (s1.back() == '1' || s2.back() == '1')
            {
                map = '#' + map;
            }
            else
            {
                map = ' ' + map;
            }

            s1.pop_back();
            s2.pop_back();
        }

        while (!s1.empty())
        {
            if (s1.back() == '1')
            {
                map = '#' + map;
            }
            else
            {
                map = ' ' + map;
            }

            s1.pop_back();
        }

        while (!s2.empty())
        {
            if (s2.back() == '1')
            {
                map = '#' + map;
            }
            else
            {
                map = ' ' + map;
            }

            s2.pop_back();
        }

        while (map.length() < n)
        {
            map = ' ' + map;
        }

        answer.push_back(map);
    }

    return answer;
}

string ToBinary(int n)
{
    string s;

    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }

    return s;
}
