#include <string>
#include <vector>

using namespace std;

bool CanPronounce(const string& word);

int solution(vector<string> babbling)
{
    int answer = 0;

    for (const auto& word : babbling)
    {
        // �� �ܾ ��ȸ�ϸ�, ������ �� �ִٸ� answer�� 1 ������Ų��.
        if (CanPronounce(word))
        {
            ++answer;
        }
    }

    return answer;
}

bool CanPronounce(const string& word)
{
    // ������ �� �ִ� �ܾ�
    static const string words[] = { "aya", "ye", "woo", "ma" };
    string prev;

    // word�� ���ڸ� ��ȸ�ϸ�, ������ �� �ִ� �ܾ �����ϰ� �ִ��� �˻��Ѵ�.
    for (int i = 0; i < word.size(); )
    {
        bool isPossible = false;

        for (int j = 0; j < 4; ++j)
        {
            // �ε��� i���� words[i]�� ���̸�ŭ�� �˻��Ͽ�, ���Կ��θ� �Ǵ��Ѵ�.
            string part = word.substr(i, words[j].length());

            // �����ؼ� ���� ������ ���� ���ϹǷ�, part�� prev�� ���� �����鼭 �����ϴ� ��쿡 isPossible�� true�� ����� i�� part�� ���̸�ŭ ������Ų��.
            if ((part != prev) && (part == words[j]))
            {
                isPossible = true;
                prev = part;
                i += part.length();
                break;
            }
        }

        // ������ �� �ִ� �ܾ �����ϰ� ���� �ʴٸ�, false�� ��ȯ�Ѵ�.
        if (!isPossible)
        {
            return false;
        }
    }

    return true;
}
