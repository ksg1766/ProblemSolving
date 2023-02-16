#include <iostream>
#include <vector>
using namespace std;

struct User
{
    int age;
    string name;
};

bool compare(const User& u1, const User& u2)
{
    if (u1.age >= u2.age)
        return true;
    else
        return false;
}

void MergeResult(vector<User>& v, int left, int mid, int right)
{
    int leftIdx = left;
    int rightIdx = mid + 1;
    vector<User> temp;
    
    while (leftIdx <= mid && rightIdx <= right)
    {
        if (compare(v[rightIdx], v[leftIdx]))
        {
            temp.push_back(v[leftIdx]);
            ++leftIdx;
        }
        else
        {
            temp.push_back(v[rightIdx]);
            ++rightIdx;
        }
    }

    if (leftIdx > mid)
        while (rightIdx <= right)
        {
            temp.push_back(v[rightIdx]);
            ++rightIdx;
        }
    else
        while (leftIdx <= mid)
        {
            temp.push_back(v[leftIdx]);
            ++leftIdx;
        }

    for (int i = 0; i < temp.size(); i++)
        v[left + i] = temp[i];
}

void MergeSort(vector<User>& u, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    MergeSort(u, left, mid);
    MergeSort(u, mid + 1, right);

    MergeResult(u, left, mid, right);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<User> u;
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        User tempUser;
        cin >> tempUser.age >> tempUser.name;
        u.push_back(tempUser);
    }
    MergeSort(u, 0, N - 1);

    for (int i = 0; i < N; ++i)
        cout << u[i].age << ' ' << u[i].name << '\n';

    return 0;
}