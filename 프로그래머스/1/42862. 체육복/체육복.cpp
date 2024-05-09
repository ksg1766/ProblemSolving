#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> all(n + 1, 1);
    
    for(int i = 0; i < lost.size(); ++i)
    {
        --all[lost[i]];
    }
    
    for(int i = 0; i < reserve.size(); ++i)
    {
        ++all[reserve[i]];
    }
    
    for(int i = 1; i <= n; ++i)
    {
        if(0 == all[i])
        {
            if(2 == all[i - 1])
            {
                ++all[i];
                --all[i - 1];
            }            
            else if(i < n && 2 == all[i + 1])
            {
                ++all[i];
                --all[i + 1];
            }
        }
    }
    
    for(int i = 1; i <= n; ++i)
    {
        if (0 != all[i]) ++answer;
    }
    
    return answer;
}