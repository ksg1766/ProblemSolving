#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int input;
        cin >> input;
        if (!input)
            break;

        int reverse = 0;

        for (int temp = input; temp; temp /= 10)
        {
            reverse *= 10;
            reverse += temp % 10;
        }
        if (input == reverse)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}