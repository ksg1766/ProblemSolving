#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int min = 0;
    
    while(pq.top() < K)
    {
        if(pq.size() == 1)
        {
            answer = -1;
            break;
        }
        
        min = pq.top();
        
        pq.pop();
        
        pq.emplace(min + 2 * pq.top());
        pq.pop();
        
        ++answer;
    }
    
    return answer;
}