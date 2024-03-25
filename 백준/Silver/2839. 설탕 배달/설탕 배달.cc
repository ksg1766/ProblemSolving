#include <iostream>

using namespace std;

int cache[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;

    cin >> N;

    cache[3] = cache[5] = 1;

    for (int i = 6; i <= N; ++i)
    {
        if (cache[i - 3]) 
        {
            cache[i] = cache[i - 3] + 1; 
        }

        if (cache[i - 5])
        {
            cache[i - 3] ? cache[i] = min(cache[i - 3], cache[i - 5]) + 1 : cache[i] = cache[i - 5] + 1;
        }
    }

    int result = 0;

    cache[N] ? result = cache[N] : result = -1;

    cout << result;

    return 0;
}