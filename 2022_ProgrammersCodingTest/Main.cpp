#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int cardCount{ static_cast<int>(sizes.size()) };
    int maxWidth{ INT_MIN };
    int maxHeight{ INT_MIN };

    for (int i = 0; i < cardCount; ++i)
    {
        int longerEdge{ max(sizes[i][0], sizes[i][1]) };
        int shorterEdge{ min(sizes[i][0], sizes[i][1]) };

        if (longerEdge > maxWidth)
        {
            maxWidth = longerEdge;
        }

        if (shorterEdge > maxHeight)
        {
            maxHeight = shorterEdge;
        }
    }

    return maxWidth * maxHeight;
}
