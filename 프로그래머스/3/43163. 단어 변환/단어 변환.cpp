#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<bool>>& connected, vector<bool>& visited, vector<int>& dist,
         int start, int dest)
{
    if(-1 == dest)
        return 0;
    
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    int size = start;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < size; ++i)
        {
            if (curr == i || true == visited[i])
                continue;
            
            if (true == connected[curr][i])
            {                
                dist[i] = dist[curr] + 1;
                
                if(i == dest)
                    return dist[i];
                
                q.push(i);
                visited[i] = true;
            }          
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    words.push_back(begin);
    
    int size = words.size();
    int length = words[0].length();
    
    int dest = -1;
    
    vector<vector<bool>> connected(size, vector<bool>(size, false));
    vector<bool> visited(size, false);
    vector<int> dist(size, 0);
    
    for(int i = 0; i < size; ++i)
    {
        if(-1 == dest && target == words[i])
            dest = i;
        
        for(int j = i + 1; j < size; ++j)
        {
            int count = 0;

            for (int k = 0; k < length; ++k)
            {
                if (words[i][k] != words[j][k])
                    ++count;
                
                if (count > 1)
                    break;
            }
            
            if(1 == count)
                connected[i][j] = connected[j][i] = true;
        }
    }
    
    answer = BFS(connected, visited, dist, size - 1, dest);
    
    return answer;
}