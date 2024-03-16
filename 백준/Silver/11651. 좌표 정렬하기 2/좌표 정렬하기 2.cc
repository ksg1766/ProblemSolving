#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tagCoord
{
    tagCoord(int _x, int _y) { x = _x; y = _y; }

    int x = 0;
    int y = 0;

    bool operator<(const tagCoord& other) const
    {
        if (y != other.y)
            return y < other.y;

        return x < other.x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input = 0;
    int x, y = 0;
    vector<tagCoord> vec;

    cin >> input;

    for(int i = 0; i < input; ++i)
    {
        cin >> x >> y;
        vec.push_back(tagCoord(x, y));
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i].x << ' ' << vec[i].y << '\n';
    }

    return 0;
}