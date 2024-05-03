#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int n = 0; n < commands.size(); ++n)
    {
        vector<int> cut;
        
        for(int i = commands[n][0] - 1; i < commands[n][1]; ++i)
        {
            cut.emplace_back(array[i]);
        }
        
        sort(cut.begin(), cut.end());
        
        answer.emplace_back(cut[commands[n][2] - 1]);
    }
    
    return answer;
}