#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int& target, int depth, int sum, int& count)
{
    if(depth < 0)
    {
        if(sum == target)
        {
            ++count;            
        }
        
        return;
    }
    
    DFS(numbers, target, depth - 1, sum + numbers[depth], count);
    DFS(numbers, target, depth - 1, sum - numbers[depth], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
        
    DFS(numbers, target, numbers.size() - 1, sum, answer);
    
    return answer;
}
