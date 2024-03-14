#include <iostream>
#include <limits.h>

using namespace std;

char control[8][8] =
{ 
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', 
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
};

void BoardChecker(char board[50][50], int& ws, int& hs, int& record);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width = 0;
    int height = 0;
    int result = INT_MAX;

    char board[50][50] = {};

    cin >> width >> height;

    for (int i = 0; i < width; ++i)
    {
        cin >> board[i];
    }

    for (int i = 0; i + 8 <= width; ++i)
    {
        for (int j = 0; j + 8 <= height; ++j)
        {
            int record = 0;

            BoardChecker(board, i, j, record);
            result = min(result, record);
        }
    }

    cout << result;

    return 0;
}

void BoardChecker(char board[50][50], int& ws, int& hs, int& record)
{
    int wr = 0;
    int br = 0;

    for (int i = 0; i < 8; ++i)
    {
        int _i = i + ws;

        for (int j = 0; j < 8; ++j)
        {
            if ((control[i][j] != board[_i][j + hs]))
            {
                ++wr;
            }
            else
            {
                ++br;
            }
        }
    }

    record = min(wr, br);
}