#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    
    int iCount = people.size();
    
    int iLeft = 0;
    int iRight = iCount - 1;
    
    sort(people.begin(), people.end());

    while(iLeft <= iRight)
    {
        ++answer;
        
        int capacity = limit - people[iRight--];
        
        if(capacity >= people[iLeft] && iLeft <= iRight)
        {
            ++iLeft;            
        } 
    }
        
    return answer;
}