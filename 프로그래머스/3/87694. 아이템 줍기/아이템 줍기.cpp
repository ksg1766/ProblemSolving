#include <string>
#include <vector>
#include <queue>

using namespace std;

void BlockArea(vector<vector<int>>& rectangle, vector<vector<bool>>& cango)
{
    for(int i = 0; i < rectangle.size(); ++i)
    {
        int lbx = 2 * rectangle[i][0];
        int lby = 2 * rectangle[i][1];
        int rtx = 2 * rectangle[i][2];
        int rty = 2 * rectangle[i][3];
        
        for(int j = lby; j <= rty; ++j)
        {
            for(int k = lbx; k <= rtx; ++k)
            {
                cango[j][k] = true;
            }        
        }
    }
    
    for(int i = 0; i < rectangle.size(); ++i)
    {
        int lbx = 2 * rectangle[i][0];
        int lby = 2 * rectangle[i][1];
        int rtx = 2 * rectangle[i][2];
        int rty = 2 * rectangle[i][3];
        
        for(int j = lby + 1; j < rty; ++j)
        {
            for(int k = lbx + 1; k < rtx; ++k)
            {
                cango[j][k] = false;
            }        
        }
    }
}

int BFS(vector<vector<bool>>& cango, vector<vector<int>>& dist,
         int characterY, int characterX, int itemY, int itemX, int minY, int minX, int maxY, int maxX)
{
    queue<pair<int, int>> q;
    
    cango[characterY][characterX] = false;
    q.emplace(characterY, characterX);
    
    while(!q.empty())
    {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        for(int i = 0; i < 4; ++i)
        {
            int nextY = currY + dy[i];
            if(nextY > maxY || nextY < minY)
                continue;
            
            int nextX = currX + dx[i];
            if(nextX > maxX || nextX < minX)
                continue;
            
            if(true == cango[nextY][nextX])
            {
                dist[nextY][nextX] = dist[currY][currX] + 1;
                if(nextY == itemY && nextX == itemX)
                    return dist[nextY][nextX];                    
                
                cango[nextY][nextX] = false;                
                q.emplace(nextY, nextX);
            }
        }
    }
    
     return dist[itemY][itemX];          
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) { 
    int answer = 0;
    
    int maxY = 1;
    int maxX = 1;
    int minY = 50;
    int minX = 50;
    
    for(int i = 0; i < rectangle.size(); ++i)
    {
        minX = min(minX, rectangle[i][0]);
        minY = min(minY, rectangle[i][1]);
        maxX = max(maxX, rectangle[i][2]);
        maxY = max(maxY, rectangle[i][3]);        
    }
        
    vector<vector<bool>> cango(102, vector<bool>(102, false));
    vector<vector<int>> dist(102, vector<int>(102, 0));
    
    BlockArea(rectangle, cango);
    
    answer = BFS(cango, dist, 2 * characterY, 2 * characterX, 2 * itemY, 2 * itemX,
               2 * minY, 2 * minX, 2 * maxY, 2 * maxX);
    
    answer /= 2;
    
    return answer;    
}