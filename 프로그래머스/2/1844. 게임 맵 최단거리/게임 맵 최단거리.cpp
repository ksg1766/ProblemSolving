#include<vector>
#include<queue>
using namespace std;

int BFS(vector<vector<int>>& maps, vector<vector<int>>& cache)
{
    int dir[4][2] =
    {
        {0, +1},
        {0, -1},
        {+1, 0},
        {-1, 0}        
    };
    
    queue<pair<int, int>> q;
    
    int y = 0; 
    int x = 0;
    
    int destY = maps.size() - 1;
    int destX = maps[0].size() - 1;
    
    vector<vector<int>> dist(destY + 1, vector<int>(destX + 1, -1));
    
    bool isArrived = false;
    
    q.emplace(y, x);
    cache[y][x] = 0;
    dist[y][x] = 1;
    
    while(!q.empty())
    {
        if(true == isArrived)
            break;
        
        pair<int, int> currPair = q.front();
        q.pop();
        
        y = currPair.first;
        x = currPair.second;
        
        if(destY == y && destX == x)
        {
             isArrived = true;
                    
             break;
        }   
        
        for(int i = 0; i < 4; ++i)
        {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];
            
            if(nextY > destY || nextX > destX || nextY < 0 || nextX < 0)
            {
                continue;
            }
            
            if(cache[nextY][nextX])
            {                
                cache[nextY][nextX] = 0;    
                dist[nextY][nextX] = 1 + dist[y][x];
                q.emplace(nextY, nextX);
            }
        }        
    }
    
    if(isArrived)
    {                
        return dist[destY][destX];
    }
    else
    {
        return -1;
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    //vector<vector<int>> cache(vector<int>(maps.size(), maps[0].size());
    vector<vector<int>> cache(maps);

    answer = BFS(maps, cache);
    
    return answer;
}