#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input[100] = { 0 };
    int arr[1001] = { 0 };
    int N;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    arr[0] = 1;
    arr[1] = 1;

    for (int j = 2; j <= static_cast<int>(sqrt(1001)); j++)
    {
        for (int i = 2; i <= 1001 / j; i++)
            if(arr[j * i] == 0)
                ++arr[j * i];
    }

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (input[i] == 1)
            continue;
        
        if (arr[input[i]] == 0)
            ++cnt;
    }

    cout << cnt;
    return 0;
}