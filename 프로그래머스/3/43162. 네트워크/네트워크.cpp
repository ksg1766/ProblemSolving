#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& computers, vector<int>& cache, int from)
{    
    int size = computers.size();
    
    cache[from] = 0;
    
    for(int to = 0; to < size; ++to)
    {
        if(from == to)
            continue;
        
        if(1 == cache[to])
        {
            if(1 == computers[from][to])
                DFS(computers, cache, to);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    int size = computers.size();
    vector<int> cache(size, 1);
    
    for (int i = 0; i < size; ++i)
    {
        if(1 == cache[i])
        {
            DFS(computers, cache, i);
            ++answer;
        }
    }
    
    return answer;
}