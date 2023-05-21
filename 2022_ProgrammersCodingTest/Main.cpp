#include <string>
#include <vector>

using namespace std;

bool CanPronounce(const string& word);

int solution(vector<string> babbling)
{
    int answer = 0;

    for (const auto& word : babbling)
    {
        // 각 단어를 순회하며, 발음할 수 있다면 answer를 1 증가시킨다.
        if (CanPronounce(word))
        {
            ++answer;
        }
    }

    return answer;
}

bool CanPronounce(const string& word)
{
    // 발음할 수 있는 단어
    static const string words[] = { "aya", "ye", "woo", "ma" };
    string prev;

    // word의 문자를 순회하며, 발음할 수 있는 단어를 포함하고 있는지 검사한다.
    for (int i = 0; i < word.size(); )
    {
        bool isPossible = false;

        for (int j = 0; j < 4; ++j)
        {
            // 인덱스 i부터 words[i]의 길이만큼을 검사하여, 포함여부를 판단한다.
            string part = word.substr(i, words[j].length());

            // 연속해서 같은 발음을 하지 못하므로, part와 prev가 같지 않으면서 포함하는 경우에 isPossible을 true로 만들고 i를 part의 길이만큼 증가시킨다.
            if ((part != prev) && (part == words[j]))
            {
                isPossible = true;
                prev = part;
                i += part.length();
                break;
            }
        }

        // 발음할 수 있는 단어를 포함하고 있지 않다면, false를 반환한다.
        if (!isPossible)
        {
            return false;
        }
    }

    return true;
}
