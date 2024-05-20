#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v(numbers.size());
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        v[i] = to_string(numbers[i]);
    }
    
    sort(v.begin(), v.end(), [](const string& a, const string& b){
        return a + b > b + a;
    });

    if(v[0].compare("0")==0)
        return "0";
    
    for(int i = 0; i < v.size(); ++i)
    {
        answer += v[i];
    }

    return answer;
}