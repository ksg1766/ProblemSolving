#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 0;
    int input = 0;
    stack<int> s;

    cin >> k;

    for(int i = 0; i < k; ++i)
    {
        cin >> input;

        if (input)
            s.push(input);
        else
            s.pop();
    }

    int result = 0;

    for(int i = 0; !s.empty(); ++i)
    {
        result += s.top();

        s.pop();
    }

    cout << result << '\n';

    return 0;
}