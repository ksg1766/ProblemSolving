#include <iostream>
#include <vector>

using namespace std;

struct tagData
{
    tagData(int x, int y) { w = x; h = y; }
    int w, h = 0;
    int rank = 1;
    
    bool operator<(const tagData& other) const
    {
        if (w < other.w && h < other.h)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input = 0;
    int h, w = 0;
    vector<tagData> vec;
    
    vec.reserve(50);

    cin >> input;

    for(int i = 0; i < input; ++i)
    {
        cin >> h >> w;
        vec.push_back(tagData(h, w));
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[i] < vec[j])
            {
                ++vec[i].rank;
            }
        }
    }

    for (tagData tDatam : vec)
    {
        cout << tDatam.rank << ' ';
    }

    return 0;
}