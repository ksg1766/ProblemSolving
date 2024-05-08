#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
      
    int total = brown + yellow;
    
    int maxRow = sqrt(total);
    
    for(int i = 3; i <= maxRow; ++i)
    {
        if(0 == total % i)
        {
            if(yellow == (total - 2 * i - 2 * ( total / i  - 2 )))
            {
                answer.push_back(total / i);
                answer.push_back(i);
            }
        }
    }
    
    return answer;
}