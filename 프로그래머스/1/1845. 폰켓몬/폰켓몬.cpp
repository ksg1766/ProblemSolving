#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int N = nums.size();
    set<int> numSet;
    
    for(int i = 0; i < N; ++i)
    {
        numSet.emplace(nums[i]);
    }
    
    if(numSet.size() >= N / 2)
        answer = N / 2;
    else
        answer = numSet.size();
    
    return answer;
}