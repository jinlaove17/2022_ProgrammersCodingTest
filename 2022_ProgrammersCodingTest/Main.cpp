#include <string>

using namespace std;

int solution(string word)
{
    int answer = 0;

    string s;

    while (s != word)
    {
        if (s.length() < 5)
        {
            s.push_back('A');
        }
        else
        {
            while (s.back() == 'U')
            {
                s.pop_back();
            }

            char& back = s.back();

            switch (back)
            {
            case 'A':
                back = 'E';
                break;
            case 'E':
                back = 'I';
                break;
            case 'I':
                back = 'O';
                break;
            case 'O':
                back = 'U';
                break;
            }
        }

        ++answer;
    }

    return answer;
}
