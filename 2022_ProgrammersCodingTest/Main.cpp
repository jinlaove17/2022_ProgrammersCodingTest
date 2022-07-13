#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer{};

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); ++i)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}


//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion)
//{
//    string answer{};
//
//    const set<string> uniqueParticipantNames{ participant.cbegin(), participant.cend() };
//    const set<string> uniqueCompletionNames{ completion.cbegin(), completion.cend() };
//
//    if (uniqueParticipantNames.size() != uniqueCompletionNames.size())
//    {
//        for (auto iter = uniqueParticipantNames.cbegin(); iter != uniqueParticipantNames.cend(); ++iter)
//        {
//            if (uniqueCompletionNames.find(*iter) == uniqueCompletionNames.cend())
//            {
//                answer = *iter;
//                break;
//            }
//        }
//    }
//    else
//    {
//         const multiset<string> participantNames{ participant.cbegin(), participant.cend() };
//         const multiset<string> completionNames{ completion.cbegin(), completion.cend() };
//         
//        for (auto iter = uniqueParticipantNames.cbegin(); iter != uniqueParticipantNames.cend(); ++iter)
//        {
//            if (participantNames.count(*iter) != completionNames.count(*iter))
//            {
//                answer = *iter;
//                break;
//            }
//        }
//    }
//
//    return answer;
//}
