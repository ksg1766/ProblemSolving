#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sample = 0;
    
    int counter = 0;

    vector<int> vecInputs;
    vector<int> vecStack;

    vector<char> vecResult;
    
    cin >> sample;

    for (int i = 0; i < sample; ++i)
    {
        int input = 0;
        cin >> input;
        vecInputs.push_back(input);
    }

    for (int i = 0; i < vecInputs.size(); )
    {
        if (!vecStack.empty())
        {
            if (vecStack.back() == vecInputs[i])
            {
                vecStack.pop_back();
                vecResult.push_back('-');
                ++i;
            }
            else if (vecStack.back() > vecInputs[i])
            {
                cout << "NO" << '\n';
                return 0;
            }
            else if (vecStack.back() < vecInputs[i])
            {
                vecStack.push_back(++counter);
                vecResult.push_back('+');
            }
        }
        else
        {
            vecStack.push_back(++counter);
            vecResult.push_back('+');
        }
    }

    for (int i = 0; i < vecResult.size(); ++i)
    {
        cout << vecResult[i] << '\n';
    }

    return 0;
}