#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool arrPrimes[1000001] = { false };

    int M = 0;
    int N = 0;

    cin >> M >> N;

    for (int i = 2; i * i <= N; ++i)
    {
        if (arrPrimes[i])
            continue;
        for (int j = 2 * i; j <= N; j += i)
        {
            if (arrPrimes[j])
                continue;
            arrPrimes[j] = true;
        }
    }

    for (int i = max(M, 2); i <= N; ++i)
    {
        if (arrPrimes[i])
            continue;
        cout << i << '\n';
    }

    return 0;
}