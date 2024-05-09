#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, vector<bool>> hash;
    
    for(auto& iter : completion)
    {
        const auto& pair = hash.find(iter);
        if (pair == hash.end())
        {
            vector<bool> v(1, false);
            hash.emplace(iter, v);
        }
        else
        {
            pair->second.emplace_back(false);
        }
    }
    
    for(auto& iter : participant)
    {
        const auto& pair = hash.find(iter);
        
        if (pair == hash.end())
        {
            return iter;
        }
        else
        {
            if(false == pair->second.empty())
                pair->second.pop_back();
            else
            {
                return iter;
            }
        }
    }
}