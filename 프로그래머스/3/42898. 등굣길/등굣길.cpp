#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> cost(n + 1, vector<int>(m + 1, 0));
    
    for(auto& iter : puddles)
        cost[iter[1]][iter[0]] = -1;
    
    for(int i = 1; i <= n; ++i)
    {
        if(-1 == cost[i][1])
            break;
        
        cost[i][1] = 1;
    }
    
    for(int i = 1; i <= m; ++i)
    {
        if(-1 == cost[1][i])
            break;
        
        cost[1][i] = 1;
    }
    
    for(int i = 2; i <= m; ++i)
    {
        for(int j = 2; j <= n; ++j)
        {    
            if(-1 == cost[j][i])
                continue;
            
            int left, up;
            
            if(-1 != cost[j - 1][i])
                left = cost[j - 1][i];
            else
                left = 0;
            
            if(-1 != cost[j][i - 1])
                up = cost[j][i - 1];
            else
                up = 0;
                
            cost[j][i] = (left + up) % 1000000007;
        }
    }
    
    return cost[n][m];
}