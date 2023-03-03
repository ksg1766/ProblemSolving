#include <iostream>

using namespace std;

int cache[50][50] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    char arr[50][50] = {};
    int iResult = 2500;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];


    int iWcount0, iWcount1;
    int iBcount0, iBcount1;

    int a = 0, b;

    while (a <= N - 8)
    {
        b = 0;
        while (b <= M - 8)
        {
            iWcount0 = 0;
            iWcount1 = 0;
            for (int i = a; i < a + 8; ++i)
            {
                for (int j = b; j < b + 8; ++j)
                {
                    if (((i + j) % 2) == 0)
                        if (arr[i][j] == 'W')
                            ++iWcount0;

                    if (((i + j) % 2) == 1)
                        if (arr[i][j] == 'W')
                            ++iWcount1;
                }
            }

            int iAll = N * M;

            iBcount0 = 32 - iWcount0;
            iBcount1 = 32 - iWcount1;

            int iGap0 = 64 - (iWcount0 + iBcount1);
            int iGap1 = 64 - (iWcount1 + iBcount0);

            if (iGap0 < iGap1)
            {
                if (iGap0 < iResult)
                    iResult = iGap0;
            }
            else
            {
                if (iGap1 < iResult)
                    iResult = iGap1;
            }

            ++b;
        }
        ++a;
    }

    cout << iResult;

    return 0;
}