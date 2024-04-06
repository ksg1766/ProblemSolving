#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cut;
    int avg = 0;

    cin >> n;

    if (0 == n)
    {
        cout << '0' << '\n';
        return 0;
    }

    vector<int> v(n + 1, 0);

    cut = round(n * 0.15f);

    for (int i = 1; i <= n; ++i)
    {
        int input;
        cin >> input;

        v[i] = input;
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; ++i)
    {
        if (i <= cut || i >= n + 1 - cut)
        {
            continue;
        }

        avg += v[i];
    }

    cout << round(avg / (float)(n - 2 * cut)) << '\n';

    return 0;
}