#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int score[3] = {0};
    
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == (i % 5) + 1)
            ++score[0];
        
        if (0 == i % 2)
        {
            if (2 == answers[i])
                ++score[1];
        }
        else
        {
            if ((1 == i % 8 && 1 == answers[i])
                || (3 == i % 8 && 3 == answers[i])
                || (5 == i % 8 && 4 == answers[i])
                || (7 == i % 8 && 5 == answers[i]))
                ++score[1];
        }
        
        if (((0 <= i % 10) && (i % 10 < 2)) && (3 == answers[i])
           || ((2 <= i % 10) && (i % 10 < 4)) && (1 == answers[i])
           || ((4 <= i % 10) && (i % 10 < 6)) && (2 == answers[i])
           || ((6 <= i % 10) && (i % 10 < 8)) && (4 == answers[i])
           || ((8 <= i % 10) && (i % 10 < 10)) && (5 == answers[i]))
             ++score[2];        
    }
    
    if(score[0] == score[1])
    {
        if(score[1] == score[2])
        {
            for(int i = 1; i <= 3; ++i)
                answer.push_back(i);
        }
        else if (score[1] > score[2])
        {
            for(int i = 1; i <= 2; ++i)
                answer.push_back(i);
        }
        else
            answer.push_back(2);
    }
    else if(score[0] < score[1])
    {
        if(score[1] == score[2])
        {
            answer.push_back(2);
            answer.push_back(3);
        }
        else if (score[1] < score[2])
        {
            answer.push_back(3);
        }
        else
            answer.push_back(2);
    }
    else // score[0] > score[1]
    {
        if(score[0] == score[2])
        {
            answer.push_back(1);
            answer.push_back(3);
        }
        else if (score[0] < score[2])
        {
            answer.push_back(3);
        }
        else
            answer.push_back(1);
    }
    
    return answer;
}