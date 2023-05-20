#include <string>
#include <map>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";

    // 가장 큰 정수를 만들어야하므로, 문자를 기준으로 큰 수부터 접근할 수 있는 컨테이너인 map을 사용한다.
    // map은 기본적으로 오름차순 정렬이므로, 템플릿의 3번째 인자로 greater<char>를 넣어주어 내림차순 정렬로 생성한다.
    map<char, int, greater<char>> m1, m2;

    // 문자열 X에 있는 각 문자의 개수를 m1에 저장한다.
    for (char c : X)
    {
        ++m1[c];
    }

    // 문자열 Y에 있는 각 문자의 개수를 m2에 저장한다.
    for (char c : Y)
    {
        ++m2[c];
    }

    // m1의 문자를 순회하며 m2에 있는지 검사하고, 있을 경우에는 더 적은 개수만큼 answer에 이어 붙인다.
    for (const auto& p : m1)
    {
        if (m2.find(p.first) != m2.end())
        {
            answer += string(min(p.second, m2[p.first]), p.first);
        }
    }

    // 하나라도 같은 문자가 없었다면, answer에 "-1"을 대입한다.
    if (answer.empty())
    {
        answer = "-1";
    }
    // 두 문자가 0을 여러개 가지는 경우가 있으므로, answer에 "0"을 대입한다.
    else if (answer.front() == '0')
    {
        answer = "0";
    }

    return answer;
}
