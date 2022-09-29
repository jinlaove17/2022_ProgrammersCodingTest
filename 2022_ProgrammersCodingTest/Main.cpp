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

        // 마지막 토큰인 name에 대하여 NULL체크를 안하면 값이 이상하다.(이유?)
        if (name != NULL)
        {
            um[uid] = name;
        }

        if (strcmp(state, "Enter") == 0)
        {
            answer.emplace_back("님이 들어왔습니다.");
        }
        else if (strcmp(state, "Leave") == 0)
        {
            answer.emplace_back("님이 나갔습니다.");
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
