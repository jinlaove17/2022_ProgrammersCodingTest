#include <string>
#include <map>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";

    // ���� ū ������ �������ϹǷ�, ���ڸ� �������� ū ������ ������ �� �ִ� �����̳��� map�� ����Ѵ�.
    // map�� �⺻������ �������� �����̹Ƿ�, ���ø��� 3��° ���ڷ� greater<char>�� �־��־� �������� ���ķ� �����Ѵ�.
    map<char, int, greater<char>> m1, m2;

    // ���ڿ� X�� �ִ� �� ������ ������ m1�� �����Ѵ�.
    for (char c : X)
    {
        ++m1[c];
    }

    // ���ڿ� Y�� �ִ� �� ������ ������ m2�� �����Ѵ�.
    for (char c : Y)
    {
        ++m2[c];
    }

    // m1�� ���ڸ� ��ȸ�ϸ� m2�� �ִ��� �˻��ϰ�, ���� ��쿡�� �� ���� ������ŭ answer�� �̾� ���δ�.
    for (const auto& p : m1)
    {
        if (m2.find(p.first) != m2.end())
        {
            answer += string(min(p.second, m2[p.first]), p.first);
        }
    }

    // �ϳ��� ���� ���ڰ� �����ٸ�, answer�� "-1"�� �����Ѵ�.
    if (answer.empty())
    {
        answer = "-1";
    }
    // �� ���ڰ� 0�� ������ ������ ��찡 �����Ƿ�, answer�� "0"�� �����Ѵ�.
    else if (answer.front() == '0')
    {
        answer = "0";
    }

    return answer;
}
