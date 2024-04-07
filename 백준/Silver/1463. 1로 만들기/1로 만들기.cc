#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1000001];
    int N;

    cin >> N;

    arr[1] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for (int i = 4; i < N + 1; ++i)
    {
        arr[i] = arr[i - 1] + 1;

        if (0 == i % 2)
        {
            arr[i] = min(arr[i / 2] + 1, arr[i]);
        }
        
        if (0 == i % 3)
        {
            arr[i] = min(arr[i / 3] + 1, arr[i]);
        }
    }

    cout << arr[N];

    return 0;
}