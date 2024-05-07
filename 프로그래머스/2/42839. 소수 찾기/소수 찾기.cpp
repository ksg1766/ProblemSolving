#include <string>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPrime(int integer)
{
    int rt = sqrt(integer);
    
    if(integer < 2)
        return false;
    
    for(int i = 2; i <= rt; ++i)
    {
        if (0 == integer % i)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    set<int> answers;
    
    sort(numbers.begin(), numbers.end());
    
    do
    {
        string cache;
    
        for(int i = 0; i < numbers.length(); ++i)
        {
           cache += numbers[i];
        
           if(IsPrime(stoi(cache)))
               answers.emplace(stoi(cache));
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    
    return answers.size();
}