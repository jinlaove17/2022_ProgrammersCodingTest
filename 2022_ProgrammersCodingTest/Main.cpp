#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    int maxElapsedTime = 0;

    for (const auto& musicinfo : musicinfos)
    {
        int startMin = 60 * stoi(musicinfo.substr(0, 2)) + stoi(musicinfo.substr(3, 2));
        int endMin = 60 * stoi(musicinfo.substr(6, 2)) + stoi(musicinfo.substr(9, 2));
        int elapsedTime = endMin - startMin;

        string title, melody;

        for (int i = 12; i < musicinfo.length(); ++i)
        {
            if (musicinfo[i] == ',')
            {
                title = musicinfo.substr(12, i - 12);
                melody = musicinfo.substr(i + 1);
                break;
            }
        }

        string totalMelody;

        for (int i = 0, j = 0; i < elapsedTime; ++i)
        {
            totalMelody.push_back(melody[j]);
            j = (j + 1) % melody.length();

            if (melody[j] == '#')
            {
                totalMelody.push_back('#');
                j = (j + 1) % melody.length();
            }
        }

        int pos = 0;

        while ((pos = totalMelody.find(m, pos)) != string::npos)
        {
            if (totalMelody[(pos + m.length()) % totalMelody.length()] != '#')
            {
                if (elapsedTime > maxElapsedTime)
                {
                    maxElapsedTime = elapsedTime;
                    answer = title;
                    break;
                }
            }

            ++pos;
        }
    }

    return answer;
}
