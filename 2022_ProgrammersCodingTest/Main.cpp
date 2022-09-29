#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    unordered_map<string, string> um;
    int size = record.size();

    answer.reserve(size);

    for (const string& s : record)
    {
        string tmp(s);

        const char* state = strtok(const_cast<char*>(tmp.c_str()), " ");
        const char* uid = strtok(NULL, " ");
        const char* name = strtok(NULL, " ");

        // ������ ��ū�� name�� ���Ͽ� NULLüũ�� ���ϸ� ���� �̻��ϴ�.(����?)
        if (name != NULL)
        {
            um[uid] = name;
        }

        if (strcmp(state, "Enter") == 0)
        {
            answer.emplace_back("���� ���Խ��ϴ�.");
        }
        else if (strcmp(state, "Leave") == 0)
        {
            answer.emplace_back("���� �������ϴ�.");
        }
    }

    for (int i = 0, j = 0; i < size; ++i)
    {
        string tmp(record[i]);

        const char* state = strtok(const_cast<char*>(tmp.c_str()), " ");
        const char* uid = strtok(NULL, " ");

        if (strcmp(state, "Enter") == 0 || strcmp(state, "Leave") == 0)
        {
            answer[j] = um[uid] + answer[j];
            ++j;
        }
    }

    return answer;
}
