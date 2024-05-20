#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    
    for(auto& iter : clothes)
    {
        auto pair = um.find(iter[1]);
        
        if(um.end() == pair)
            um.emplace(iter[1], 1);
        else
            ++pair->second;
    }
    
    for(auto pair = um.begin(); pair != um.end(); ++pair)
    {
        answer *= (pair->second + 1);
    }    
    
    return answer - 1;
}