#include <iostream>
#include <algorithm>
using namespace std;

struct Pos
{
    int x;
    int y;
};

bool compPos(const Pos& p1, const Pos& p2)
{
    if (p1.x > p2.x)
        return false;
    else if (p1.x < p2.x)
        return true;
    else
        if (p1.y >= p2.y)
            return false;
        else
            return true;
}

int Partition(Pos* arr, int left, int right)
{
    Pos pivot = arr[left];
    int low = left + 1;
    int high = right;
    while (low <= high) 
    {
        while (low <= right && compPos(pivot, arr[low]))
        {
            ++low;
        }

        while (high >= left + 1 && compPos(arr[high], pivot))
        {
            --high;
        }

        if (low < high)
            swap(arr[low], arr[high]);
    }
    swap(arr[left], arr[high]);
    return high;
}

void QuickSort(Pos* v, int left, int right)
{
    if (left > right)
        return;

    int pivot = Partition(v, left, right);
    QuickSort(v, left, pivot - 1);
    QuickSort(v, pivot + 1, right);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    Pos arr[100000];
    
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i].x >> arr[i].y;

    sort(arr, arr+N, compPos);

    for (int i = 0; i < N; ++i)
        cout << arr[i].x << ' ' << arr[i].y << '\n';

    return 0;
}