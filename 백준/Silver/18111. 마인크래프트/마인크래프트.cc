#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;

    cin >> N >> M >> B;

    int area[250000];

    for(int i = 0; i < N * M; ++i)
    {
        cin >> area[i];
    }

    int iResultTime = INT_MAX;
    int iResultHeight = -1;

    for (int i = 0; i <= 256; ++i)
    {
        int iUp = 0;
        int iDown = 0;

        for (int j = 0; j < N * M; ++j)
        {
            if (i < area[j])
            {
                iDown += (area[j] - i);
            }
            else
            {
                iUp += (i - area[j]);
            }
        }

        if (iDown + B >= iUp)
        {
            int iNewTime = 2 * iDown + iUp;
            if (iNewTime < iResultTime)
            {
                iResultTime = iNewTime;
                iResultHeight = i;
            }
            else if (iNewTime == iResultTime)
            {
                if (iResultHeight < i)
                    iResultHeight = i;
            }
        }
    }

    cout << iResultTime << ' ' << iResultHeight;

    return 0;
}