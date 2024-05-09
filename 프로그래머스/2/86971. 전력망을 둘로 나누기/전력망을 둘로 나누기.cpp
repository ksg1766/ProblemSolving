#include <string>
#include <vector>
#include <set>

using namespace std;

void DFS(vector<vector<int>>& wires, vector<vector<bool>>& adjacent,
         vector<bool>& visited, int curr, int& ret)
{
    if(true == visited[curr])
        return;
    
    visited[curr] = true;
    ++ret;
    
    for(int i = 1; i < adjacent.size(); ++i)
    {
        if(false == adjacent[curr][i])
            continue;
                
        DFS(wires, adjacent, visited, i, ret);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 102;
    
    vector<vector<bool>> adjacent(n + 1, vector<bool>(n + 1, false));
    
    for(int i = 0; i < n - 1; ++i)
    {
        adjacent[wires[i][0]][wires[i][1]] = true;
        adjacent[wires[i][1]][wires[i][0]] = true;
    }
    
    for(int skip = 0; skip < n - 1; ++skip)
    {
        int ret = 0;

        vector<bool> visited(n + 1, false);
        
        adjacent[wires[skip][0]][wires[skip][1]] = false;
        adjacent[wires[skip][1]][wires[skip][0]] = false;
        
        DFS(wires, adjacent, visited, 1, ret);
        
        adjacent[wires[skip][0]][wires[skip][1]] = true;
        adjacent[wires[skip][1]][wires[skip][0]] = true;
        
        int temp = n - 2 * ret;
        answer = min(answer, std::abs(temp));
    }
    
    return answer;
}