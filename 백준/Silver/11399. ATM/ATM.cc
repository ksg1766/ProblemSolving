#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> P(N);

    for(int i = 0; i < N; ++i)
    {        
        cin >> P[i];
    }
    
    sort(P.begin(), P.end());

    int sum = 0;
    for (size_t i = 0; i < N; ++i)
    {
        sum += (N - i) * P[i];
    }

    cout << sum;

    return 0;
}