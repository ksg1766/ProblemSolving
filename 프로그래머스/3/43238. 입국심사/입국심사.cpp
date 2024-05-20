#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 1;
    long long right = n * (long long)*max_element(times.begin(), times.end());
    long long mid = 1;
    
    while(left <= right)
    {
        long long count = 0;
        
        mid = (left + right) / 2;
        
        for(auto& iter : times)
        {
            count += mid / (long long) iter;
        }
        
        if(count >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }                
    }
    
    return answer;
}