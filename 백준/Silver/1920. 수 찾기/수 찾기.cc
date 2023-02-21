#include <iostream>
#include <algorithm>

using namespace std;

//int BinarySearch(vector<int>& v, int _src);
int BinarySearch(int* arr, int size, int _src);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int arrA[100001] = {0};
    int arrM[100001] = { 0 };
    //vector<int> A, VM;

    cin >> N;
    /*for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }*/

    for (int i = 0; i < N; i++)
    {
        cin >> arrA[i];
    }

    sort(arrA, arrA + N);
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        /*  
        int temp;
        cin >> temp;
        VM.push_back(temp);
        */
        cin >> arrM[i];
    }

    for (int i = 0; i < M; i++)
        cout << BinarySearch(arrA, N, arrM[i]) << '\n';

    return 0;
}

//int BinarySearch(vector<int>& v, int _src)
int BinarySearch(int* arr, int size,int _src)
{
    int left = 0;
    int right = size - 1;
    int mid;
    //int prevMid = size + 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (_src == arr[mid])
            return 1;
        else if (_src < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}