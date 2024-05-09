#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hash;
    
    for(auto& iter : completion)
    {
        const auto& pair = hash.find(iter);
        if (pair == hash.end())
        {
            hash.emplace(iter, 1);
        }
        else
        {
            ++pair->second;
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
            if(0 == pair->second)
                return iter;
            else
                --pair->second;
        }
    }
}