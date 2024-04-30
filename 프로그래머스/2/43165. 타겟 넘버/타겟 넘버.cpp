#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int& target, int depth, int& sum, int sign, int& count)
{
    if(depth < 0)
    {
        if(sum == target)
        {
            ++count;            
        }
        
        return;
    }
    
    int tempSum = sum + sign * numbers[depth];
    
    DFS(numbers, target, depth - 1, tempSum, +1, count);
    DFS(numbers, target, depth - 1, tempSum, -1, count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
        
    DFS(numbers, target, numbers.size() - 1, sum, 1, answer);
    DFS(numbers, target, numbers.size() - 1, sum, -1, answer);
    
    return answer / 2;
}