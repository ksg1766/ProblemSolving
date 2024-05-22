#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> v(n, vector<bool>(n, false));
    
    for(int i = 0; i < results.size(); ++i)
    {
        v[results[i][0] - 1][results[i][1] - 1] = true;
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                if(v[j][i] && v[i][k])
                {
                    v[j][k] = true;
                }
            }
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        int count = 0;
        for(int j = 0; j < n; ++j)
        {
            if(v[i][j] || v[j][i])
            {
                ++count;
            }
        }
        
        if(n - 1 == count)
        {
            ++answer;
        }
    }
    
    return answer;
}