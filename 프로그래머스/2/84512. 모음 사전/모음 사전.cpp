#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    map<char, int> pair;
    pair.emplace('A', 0);
    pair.emplace('E', 1);
    pair.emplace('I', 2);
    pair.emplace('O', 3);
    pair.emplace('U', 4);
    
    int arr[5] = { 0, 1, 2, 3, 4 };
    int mul[5] = { 781, 156, 31, 6, 1 };
    
    for(int i = 0; i < word.size(); ++i)
    {
        answer += mul[i] * pair[word[i]] + 1;
    }
    
    return answer;
}