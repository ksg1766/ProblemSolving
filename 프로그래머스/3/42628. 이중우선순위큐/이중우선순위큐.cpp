#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    deque<int> dq;
    
    for(auto& iter : operations)
    {
        if('I' == iter[0])
        {
            dq.emplace_back(stoi(iter.substr(2)));
            sort(dq.begin(), dq.end());
        }
        else
        {
            if(dq.empty())
            {    
                continue;
            }
            
            if(3 == iter.length())
            {
                dq.pop_back();
            }
            else
            {
                dq.pop_front();
            }
        }
    }
    
    if(dq.empty())
    {    
        answer.emplace_back(0);
        answer.emplace_back(0);    
    }  
    
    else
    {
        answer.emplace_back(dq.back());
        answer.emplace_back(dq.front());    
    }
    return answer;
}