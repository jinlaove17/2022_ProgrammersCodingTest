#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (char c : s)
    {
        switch (c)
        {
        case '(':
            st.push(c);
            break;
        case ')':
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
            break;
        }
    }

    if (!st.empty())
    {
        answer = false;
    }

    return answer;
}
