#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;
    cin >> A >> B >> V;

    if ((V - B) % (A - B))
        cout << (V - B) / (A - B) + 1;
    else
        cout << (V - B) / (A - B);

    return 0;
}