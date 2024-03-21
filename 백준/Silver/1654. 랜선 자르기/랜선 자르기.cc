#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K = 0; // 이미 보유
    int N = 0; // 만들 갯수
    
    long long arrK[10000] = {0};

    long long mid = LLONG_MAX;
    long long max = 0;
    long long result = 0;

    cin >> K >> N;

    for (int i = 0; i < K; ++i)
    {
        cin >> arrK[i];

        if (arrK[i] < mid)
        {
            mid = arrK[i];
        }

        if (arrK[i] > max)
        {
            max = arrK[i];
        }
    }

    long long left = 1;
    long long right = max;
    
    while (left <= right)
    {
        long long count = 0;
        mid = 0.5 * (left + right);

        for (int i = 0; i < K; ++i)
        {
            count += arrK[i] / mid;
        };

        if (N <= count)
        {
            result = mid;
            left = mid + 1;            
        }
        else
        {
            right = mid - 1;
        }        
    }

    cout << result;

    return 0;
}