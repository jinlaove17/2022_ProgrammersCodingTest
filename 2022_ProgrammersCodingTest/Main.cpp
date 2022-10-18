#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string GetHead(const string& s);
int GetNumber(const string& s);

vector<string> solution(vector<string> files)
{
    stable_sort(files.begin(), files.end(),
        [](const string& a, const string& b)
        {
            string head1 = GetHead(a);
            string head2 = GetHead(b);

            if (head1 == head2)
            {
                int n1 = GetNumber(a);
                int n2 = GetNumber(b);

                return n1 < n2;
            }

            return head1 < head2;
        });

    return files;
}

string GetHead(const string& s)
{
    string head;

    for (char c : s)
    {
        if (!isdigit(c))
        {
            head.push_back(tolower(c));
        }
        else
        {
            break;
        }
    }

    return head;
}

int GetNumber(const string& s)
{
    string numStr;

    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
        {
            numStr.push_back(s[i]);

            for (int j = i + 1; j < s.length(); ++j)
            {
                if (isdigit(s[j]))
                {
                    numStr.push_back(s[j]);
                }
                else
                {
                    break;
                }
            }
        }

        if (!numStr.empty())
        {
            break;
        }
    }

    return stoi(numStr);
}
