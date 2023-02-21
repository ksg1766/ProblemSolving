#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string _left, string _right);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<string> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string iTemp;
        cin >> iTemp;
        v.push_back(iTemp);
    }
    /*string a = "abc";
    int b = a.length();
    b;*/
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        cout << v[i] << '\n';
    }

    return 0;
}

bool compare(string _left, string _right)
{
    int i = 0;
    if (_left.length() == _right.length())
        return _left < _right;
    else
        return _left.length() < _right.length();
}
