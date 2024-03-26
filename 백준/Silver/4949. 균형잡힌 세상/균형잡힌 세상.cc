#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true)
    {
        string input = "";

        vector<char> stack;
        getline(cin, input);

        if('.' == input[0])
            break;

        for (int i = 0; i < input.size(); ++i)
        {
            if ('(' == input[i] || '{' == input[i] || '[' == input[i])
                stack.push_back(input[i]);
            else if (')' == input[i])
            {
                if(stack.empty())
                {
                    cout << "no\n";
                    break;
                }
                else if ('(' == stack.back())
                    stack.pop_back();
                else
                {
                    cout << "no\n";
                    break;
                }        
            }
            else if ('}' == input[i])
            {
                if (stack.empty())
                {
                    cout << "no\n";
                    break;
                }
                else if ('{' == stack.back())
                    stack.pop_back();
                else
                {
                    cout << "no\n";
                    break;
                }
            }
            else if (']' == input[i])
            {
                if (stack.empty())
                {
                    cout << "no\n";
                    break;
                }
                else if ('[' == stack.back())
                    stack.pop_back();
                else
                {
                    cout << "no\n";
                    break;
                }
            }
            else if ('.' == input[i])
            {
                if (stack.empty())
                {
                    cout << "yes\n";
                }
                else
                {
                    cout << "no\n";
                }
                break;
            }
        }
    }

    return 0;
}