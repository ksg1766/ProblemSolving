#include <iostream>

using namespace std;

int apartment(int k, int n)
{
    if (n == 1)
        return 1;
    if (k == 0)
        return n;

    return apartment(k, n - 1) + apartment(k - 1, n);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, k, n;
    
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> k >> n;
        cout << apartment(k, n) << '\n';
    }

    return 0;
}