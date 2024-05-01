#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool DFS( unordered_map<string, vector<pair<string, bool>>>& hash, vector<string>& answer, string start, int count)
{
    answer.push_back(start);
    if(0 == count)
        return true;
        
    auto iter = hash.find(start);

    if(iter != hash.end())
    {
        for(int i = 0; i < (iter->second).size(); ++i)
        {
            if(true == (iter->second)[i].second)
                continue;
            
            (iter->second)[i].second = true;
            if(true == DFS(hash, answer, (iter->second)[i].first, count - 1))
                return true;
            
            answer.pop_back();
            (iter->second)[i].second = false;
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    int count = tickets.size();
    unordered_map<string, vector<pair<string, bool>>> hash;
    
    for(int i = 0; i < tickets.size(); ++i)
    {
        auto iter = hash.find(tickets[i][0]);
        
        if(iter != hash.end())
        {
            (iter->second).emplace_back(tickets[i][1], false);
            vector<pair<string, bool>>& refVec = iter->second;
            sort(refVec.begin(), refVec.end());            
        }
        else
        {
            vector<pair<string, bool>> v(1, make_pair(tickets[i][1], false));
            
            hash.emplace(tickets[i][0], v);
        }
    }
    
    //answer.push_back("ICN");
    
    DFS(hash, answer, "ICN", count);
    
    return answer;
}