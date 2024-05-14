#include <string>
#include <vector>
#include <queue>

using namespace std;

int mix(int min1, int min2)
{
    return min1 + 2 * min2;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto& iter : scoville)
        pq.emplace(iter);
    
    while(true)
    {
        if(pq.empty())
        {
            answer = -1;
            break;
        }
        
        int min1 = pq.top();
        
        if(min1 >= K)
            break;
        
        pq.pop();
        
        if(pq.empty())
        {
            answer = -1;
            break;
        }
        
        int min2 = pq.top();
        pq.pop();
        
        pq.emplace(min1 + 2 * min2);
        ++answer;
    }
    
    return answer;
}