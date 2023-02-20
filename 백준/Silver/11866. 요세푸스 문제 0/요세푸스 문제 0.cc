#include <iostream>
#include <queue>

using namespace std;



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;

    int n, k;

    cin >> n >> k;

    for (int i = 1; i < n + 1; i++)
        q.push(i);

    cout << '<';

    while (q.size())
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();
        if (q.size() != 0)
            cout << ", ";
    }

    cout << '>';

    return 0;
}