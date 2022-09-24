#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int len = s.length();

    for (int i = 1; i <= len; ++i)
    {
        stack<char> st;

        switch (s[0])
        {
        case '(':
        case '{':
        case '[':
        {
            st.push(s[0]);

            bool isValid = true;

            for (int j = 1; j < len; ++j)
            {
                if (s[j] == '(' ||
                    s[j] == '{' ||
                    s[j] == '[')
                {
                    st.push(s[j]);
                }
                else
                {
                    char c = st.top();

                    if ((c == '(' && s[j] == ')') ||
                        (c == '{' && s[j] == '}') ||
                        (c == '[' && s[j] == ']'))
                    {
                        st.pop();
                    }
                    else
                    {
                        isValid = false;
                        break;
                    }
                }
            }

            if (st.empty() && isValid)
            {
                ++answer;
            }
        }
        break;
        }

        rotate(s.begin(), s.begin() + 1, s.end());
    }

    return answer;
}
