#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    deque<string> cache;

    for (int i = 0; i < cities.size(); ++i)
    {
        auto iter = find_if(cache.begin(), cache.end(), [&cities, i](const auto& s)
            {
                if (_stricmp(s.c_str(), cities[i].c_str()) == 0)
                {
                    return true;
                }

                return false;
            });

        if (iter != cache.end())
        {
            ++answer;

            cache.erase(iter);
            cache.push_back(cities[i]);
        }
        else
        {
            answer += 5;

            if (cacheSize > 0)
            {
                cache.push_back(cities[i]);

                if (cache.size() > cacheSize)
                {
                    cache.pop_front();
                }
            }
        }
    }

    return answer;
}
