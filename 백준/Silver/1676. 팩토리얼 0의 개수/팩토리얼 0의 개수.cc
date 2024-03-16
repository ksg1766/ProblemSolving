#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input = 0;

    cin >> input;

    int iResult = 0;

    iResult += input / 5;
    iResult += input / 25;
    iResult += input / 125;
    
    cout << iResult;

    return 0;
}